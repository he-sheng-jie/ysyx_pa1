#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include <stdint.h>
#include <time.h>
#include "Vtop.h"

#define RAM_BASE 0x80000000
#define romsize (512*1024*1024)
#define ramsize (512*1024*1024)

uint8_t ROM[romsize];
uint8_t RAM[ramsize];

bool is_break = true;

void mem_init(char *filepath)
{
    // 初始化内存和寄存器
    memset(ROM, 0, romsize);
    memset(RAM, 0, ramsize);
    
    // 加载程序文件
    FILE *fp = fopen(filepath, "rb");
    if(!fp) {
        printf("无法打开文件: %s\n",filepath);
    }
    ///home/he/E4/sum.bin
    size_t rom_read = fread(ROM, 1, romsize, fp);
    rewind(fp);
    size_t ram_read = fread(RAM, 1, ramsize, fp);
    fclose(fp);


    // // --- 插入：将 pc=0x1220 处的 halt (0x00020067) 替换为 ebreak (0x00100073) ---
    // uint32_t ebreak_inst = 0x00100073;
    // uint32_t addr = 0x228;  // 要修改的 sum.bin 的 ROM 地址
    // // uint32_t addr = 0x1220;  // 要修改的 mem.bin 的 ROM 地址

    // // 确保地址在 ROM 范围内（可选安全检查）
    // if (addr + 3 < romsize) {
    //     // 小端序写入：逐字节写入 ebreak 指令
    //     ROM[addr + 0] = (ebreak_inst >> 0)  & 0xFF;
    //     ROM[addr + 1] = (ebreak_inst >> 8)  & 0xFF;
    //     ROM[addr + 2] = (ebreak_inst >> 16) & 0xFF;
    //     ROM[addr + 3] = (ebreak_inst >> 24) & 0xFF;
    // } else {
    //     printf("警告：地址 0x%x 超出 ROM 范围，无法插入 ebreak。\n", addr);
    // }
}



uint32_t mem_read(uint32_t pc)
{
  uint32_t inst = *(uint32_t *)&ROM[(pc - RAM_BASE) & 0x1fffffff];
  return inst;
}
extern "C" int pmem_read(int raddr) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  //printf("raddr=0x%x\n",raddr);
  if(raddr == 0x20000000) {
    return (uint32_t)time(NULL) * 1000000;
  }
  return *(uint32_t *)&RAM[(raddr &  ~0x3u & 0x1fffffff)];
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  uint32_t aligned_addr = (waddr & ~0x3u);
  //printf("waddr=0x%x  wdata = 0x%x wmask = 0x%x\n",waddr,wdata,wmask);
  if (aligned_addr == 0x10000000) {
        putchar((char)(wdata & 0xff));
  } else {
      aligned_addr = aligned_addr & 0x1fffffff ;
      if((wmask & 0Xff) == 0xff){
        *(uint32_t *)&RAM[aligned_addr] = wdata;
      } else {
            for (int i = 0; i < 4; i++) {
            if (wmask & (1 << i)) {
                RAM[aligned_addr + i] = wdata & 0xFF;
                break;
            }
        }
      }
  }

}

extern "C" void break_test(bool is_ebreak)
{
  if(is_ebreak)
    is_break = false;
  else
    is_break = true;
}


int main(int argc, char** argv) {
    mem_init(argv[1]);
    VerilatedContext* const contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop* const top = new Vtop{contextp};
  
  //while (!contextp->gotFinish()) {
    for(int i = 0; !contextp->gotFinish() && is_break; i++){
    top->inst = mem_read(top-> pc);//根据pc读取指令
    //进行一次上升沿的模拟
    top->clk = 0; top->eval();
    //printf("i=%d  pc=0X%x  inst=0X%x\n", i,top->pc, top->inst);
    top->clk = 1; top->eval();

  }
  printf("pc=0x%x",top->pc);
  if(top->result){
    printf("HIT BAD TRAP\n");
  } else {
    printf("HIT GOOD TRAP\n");
  }

    return 0;
}
