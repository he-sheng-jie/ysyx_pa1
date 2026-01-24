#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <am.h>
#include <klib-macros.h>


#define romsize (512*1024*1024)
#define ramsize (512*1024*1024)
#define N 256
#define w 256
#define h 256
#define area 256*256 


uint32_t pc = 0;
uint32_t r[32];
uint8_t ROM[romsize];
uint8_t RAM[ramsize];
uint32_t gui[N][N]={0};
 
//像素处理需要的函数
static inline uint8_t R(uint32_t p) {return p >> 16;}
static inline uint8_t G(uint32_t p) {return p >> 8;}
static inline uint8_t B(uint32_t p) {return p ;}
static inline uint32_t pixel(uint8_t r,uint8_t g,uint8_t b)
{
return (r<<16)|(g<<8)|b;
}

void draw_gui(uint32_t base,uint32_t p)
{
base = base >> 2;
uint8_t x = base & 0xff;
uint8_t y = (base & 0xff00)>>8;
gui[y][x]=p;

}

// 符号扩展函数
static inline int32_t sign_extend(uint32_t value, int bits) {
    int32_t x = (int32_t)value;
    int32_t mask = 1U << (bits - 1);
    return (x ^ mask) - mask;
}

// 指令执行周期
void inst_cycle() {
    r[0] = 0; // 确保x0始终为0
    
    
    uint32_t inst = *(uint32_t *)&ROM[pc];
    printf("pc=0x%08x inst=0x%08x ", pc, inst);
    
    uint8_t opcode = inst & 0x7F;
    uint8_t rd = (inst >> 7) & 0x1F;
    uint8_t rs1 = (inst >> 15) & 0x1F;
    uint8_t rs2 = (inst >> 20) & 0x1F;
    uint8_t funct3 = (inst >> 12) & 0x7;
    uint8_t funct7 = (inst >> 25) & 0x7F;
    
    // I-type立即数 (12位)
    int32_t imm_i = (int32_t)(inst & 0xFFF00000) >> 20;
    
    // S-type立即数 (12位)
    int32_t imm_s = ((inst & 0xFE000000) >> 20) | ((inst >> 7) & 0x1F);
    imm_s = sign_extend(imm_s, 12);
    
    // U-type立即数 (20位)
    int32_t imm_u = (int32_t)(inst & 0xFFFFF000);
    
    switch(opcode) {
        case 0x13: // I-type: 立即数运算
            switch(funct3) {
                case 0x0: // addi
                    r[rd] = r[rs1] + imm_i;
                    printf("addi x%d, x%d, %d -> x%d = 0x%08x(%d)\n", 
                           rd, rs1, imm_i, rd, r[rd], (int32_t)r[rd]);
                    break;
                default:
                    printf("未实现的I-type指令: funct3=0x%x\n", funct3);
                    exit(1);
            }
            break;
            
        case 0x33: // R-type: 寄存器运算
            switch(funct3) {
                case 0x0: 
                    if(funct7 == 0x00) { // add
                        r[rd] = r[rs1] + r[rs2];
                        printf("add x%d, x%d, x%d -> x%d = 0x%08x(%d)\n", 
                               rd, rs1, rs2, rd, r[rd], (int32_t)r[rd]);
                    } else {
                        printf("未实现的R-type指令: funct7=0x%x\n", funct7);
                        exit(1);
                    }
                    break;
                default:
                    printf("未实现的R-type指令: funct3=0x%x\n", funct3);
                    exit(1);
            }
            break;
            
        case 0x37: // U-type: lui
            r[rd] = imm_u;
            printf("lui x%d, 0x%x -> x%d = 0x%08x\n", 
                   rd, imm_u >> 12, rd, r[rd]);
            break;
            
        case 0x67: // I-type: jalr
            if(funct3 == 0x0) {
                uint32_t old_pc = pc;
                uint32_t target = (r[rs1] + imm_i) & ~1;
                if(rd != 0) {
                    r[rd] = pc + 4;
                }
                pc = target;
                printf("jalr x%d, %d(x%d) -> pc=0x%08x, x%d=0x%08x\n", 
                       rd, imm_i, rs1, pc, rd, r[rd]);
                return;
            } else {
                printf("未实现的jalr指令: funct3=0x%x\n", funct3);
                exit(1);
            }
            break;
            
        case 0x03: // I-type: 加载指令
            switch(funct3) {
                case 0x2: // lw
                    if(((r[rs1] + imm_i) & 0x3) != 0) {
                        printf("lw地址不对齐错误: 0x%08x\n", r[rs1] + imm_i);
                        exit(1);
                    }
                    r[rd] = *(uint32_t *)&RAM[r[rs1] + imm_i];
                    printf("lw x%d, %d(x%d) -> x%d = 0x%08x\n", 
                           rd, imm_i, rs1, rd, r[rd]);
                    break;
                    
                case 0x4: // lbu
                    r[rd] = RAM[r[rs1] + imm_i] & 0xFF;
                    printf("lbu x%d, %d(x%d) -> x%d = 0x%08x\n", 
                           rd, imm_i, rs1, rd, r[rd]);
                    break;
                    
                default:
                    printf("未实现的加载指令: funct3=0x%x\n", funct3);
                    exit(1);
            }
            break;
            
        case 0x23: // S-type: 存储指令
            switch(funct3) {
                case 0x0: // sb
                    RAM[r[rs1] + imm_s] = r[rs2] & 0xFF;
                    printf("sb x%d, %d(x%d) -> mem[0x%08x] = 0x%02x\n", 
                           rs2, imm_s, rs1, r[rs1] + imm_s, r[rs2] & 0xFF);
                    break;
                    
                case 0x2: // sw
                    if(((r[rs1] + imm_s) & 0x3) != 0) {
                        printf("sw地址不对齐错误: 0x%08x\n", r[rs1] + imm_s);
                        exit(1);
                    }
                    uint32_t base = r[rs1] + imm_s;
                    if((base>=0x20000000) && (base < 0X20040000))
                    	draw_gui(base,r[rs2]);
                    else
                    	*(uint32_t *)&RAM[base] = r[rs2];
                    printf("sw x%d, %d(x%d) -> mem[0x%08x] = 0x%08x\n", 
                           rs2, imm_s, rs1, r[rs1] + imm_s, r[rs2]);
                    break;
                    
                default:
                    printf("未实现的存储指令: funct3=0x%x\n", funct3);
                    exit(1);
            }
            break;
            
        case 0x73: // 系统指令
            if(inst == 0x00100073) { // ebreak
                printf("ebreak指令, a0 = %d\n", (int32_t)r[10]);
                if(r[10] == 0) {
                    printf("HIT GOOD TRAP\n");
                    exit(0);
                } else {
                    printf("HIT BAD TRAP\n");
                    exit(1);
                }
            } else {
                printf("未实现的系统指令: 0x%08x\n", inst);
                exit(1);
            }
            break;
            
        default:
            printf("未实现的指令: opcode=0x%02x\n", opcode);
            exit(1);
    }
    
    pc += 4;
}

// 初始化寄存器
void init_registers() {
    for(int i = 0; i < 32; i++) {
        r[i] = 0;
    }
}


int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("用法: %s <二进制文件>\n", argv[0]);
        return 1;
    }
    
    // 初始化内存和寄存器
    memset(ROM, 0, romsize);
    memset(RAM, 0, ramsize);
    init_registers();
    
    // 加载程序文件
    FILE *fp = fopen(argv[1], "rb");
    if(!fp) {
        printf("无法打开文件: %s\n", argv[1]);
        return 1;
    }
    
    size_t rom_read = fread(ROM, 1, romsize, fp);
    rewind(fp);
    size_t ram_read = fread(RAM, 1, ramsize, fp);
    fclose(fp);
    
    printf("加载ROM: %zu 字节, RAM: %zu 字节\n", rom_read, ram_read);
    
    // 设置初始PC（根据RISC-V规范，通常从0x0开始）
    pc = 0x0;
    
    // 执行程序
    int max_cycles = 1000000;
    printf("开始执行程序...\n\n");
    
    for(int cycle = 0; cycle < max_cycles; cycle++) {
        if(pc >= romsize - 4) {
            printf("PC超出ROM范围: 0x%08x\n", pc);
            break;
        }
        
        inst_cycle();
        io_write(AM_GPU_FBDRAW,0,0,gui,w,h,true);

    }
    
    printf("\n程序执行结束\n");
    printf("最终PC: 0x%08x\n", pc);
    printf("a0 (x10): 0x%08x (%d)\n", r[10], (int32_t)r[10]);
    
    return 0;
}
