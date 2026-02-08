#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include <stdint.h>
#include <time.h>
#include "Vtop.h"
#include "all.h"
#include "sdb.h"

#define ROM_BASE 0x80000000
#define romsize (128*1024*1024)
// #define ramsize (128*1024*1024)

uint8_t ROM[romsize];
// uint8_t RAM[ramsize];


VerilatedContext* contextp = nullptr;
Vtop* top = nullptr;

bool is_break = true;
uint32_t inst_now;

void mem_init(char *filepath)
{
    // 初始化内存和寄存器
    memset(ROM, 0, romsize);
    
    // 加载程序文件
    FILE *fp = fopen(filepath, "rb");
    if(!fp) {
        printf("无法打开文件: %s\n",filepath);
    }
    size_t rom_read = fread(ROM, 1, romsize, fp);
    fclose(fp);


    // // --- 插入：将 pc=0x1220 处的 halt (0x00020067) 替换为 ebreak (0x00100073) ---
    // uint32_t ebreak_inst = 0x00100073;
    // uint32_t addr = 0x228;  // 要修改的 sum.bin 的 ROM 地址
    // // // uint32_t addr = 0x1220;  // 要修改的 mem.bin 的 ROM 地址

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
  uint32_t inst = *(uint32_t *)&ROM[(pc - ROM_BASE) & 0x7ffffff];
  return inst;
}
extern "C" int pmem_read(int raddr,char rmask) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  uint32_t tmp;
  if(raddr == 0x20000000) {
    return (uint32_t)time(NULL) * 1000000;
  }
  if(rmask == 0x1){
    tmp = ROM[(raddr & 0x7ffffff)];
  } else if(rmask == 0x2){
    tmp = *(uint16_t *)&ROM[(raddr & 0xfffffffe & 0x7ffffff)];
  } else if(rmask == 0xff){
    tmp = *(uint32_t *)&ROM[(raddr & 0xfffffffc & 0x7ffffff)];
  } else {
    tmp = *(uint32_t *)&ROM[(raddr & 0xfffffffc & 0x7ffffff)];
  } 
  return tmp;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  uint32_t aligned_addr = (waddr & ~0x3u);
  if (aligned_addr == 0x10000000) {
    putchar((char)(wdata & 0xff));
    fflush(stdout); 
  } else {
      aligned_addr = aligned_addr & 0x7ffffff;
      if((wmask & 0Xff) == 0xff){
        *(uint32_t *)&ROM[aligned_addr] = wdata;
      } else {
            for (int i = 0; i < 4; i++) {
            if (wmask & (1u << i)) {
                ROM[aligned_addr + i] = wdata & 0xFF;
                wdata = wdata >> 8;
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

extern "C" void inst_get(int inst)
{
    inst_now = inst;
}

int main(int argc, char** argv) {
  mem_init(argv[1]);
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new Vtop{contextp};
  

  top->clk = 0;
  top->rst = 1;  
  top->eval();
  
  top->clk = 1;
  top->eval();
  
  top->rst = 0; 
  top->eval();
  sdb_init();
  sdb_loop();

  if(top->debug_rf[10]){
    printf("HIT BAD TRAP\n");
  } else {
    printf("HIT GOOD TRAP\n");
  }

    return 0;
}
