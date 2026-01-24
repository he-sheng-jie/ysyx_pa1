#include <am.h>
#include <klib-macros.h>
#include <stdlib.h>

#define k_on 10
#define k_off 100

static inline uint8_t R(uint32_t p) {return p >> 16;}
static inline uint8_t G(uint32_t p) {return p >> 8;}
static inline uint8_t B(uint32_t p) {return p ;}

static inline uint32_t pixel(uint8_t r,uint8_t g,uint8_t b)
{
return (r<<16)|(g<<8)|b;
}

int has_kbd=0;
uint32_t goat[8]={
0x000000,
0xff0000,
0x00ff00,
0x0000ff,
0xffff00,
0xff00ff,
0x00ffff,
0xffffff,
};


uint32_t tmp[300*400];
void change(int sec)
{
uint8_t r,g,b;
int k=k_off;
if(has_kbd)
{
AM_INPUT_KEYBRD_T ev=io_read(AM_INPUT_KEYBRD);
if(ev.keycode != AM_KEY_NONE)
k=k_on;
else
k=k_off;
if(ev.keycode==AM_KEY_ESCAPE)
exit(0);
}
else
k=k_off;
sec=sec%(8*k);
int j = sec/k;

r=R(goat[(j+7)%8])+(sec-k*j)*(R(goat[j])-R(goat[(j+7)%8]))/k;
g=G(goat[(j+7)%8])+(sec-k*j)*(G(goat[j])-G(goat[(j+7)%8]))/k;
b=B(goat[(j+7)%8])+(sec-k*j)*(B(goat[j])-B(goat[(j+7)%8]))/k;
int i=0;
for(i=0;i<300*400;i++)
tmp[i]=pixel(r,g,b);
}
void draw() {
  io_write(AM_GPU_FBDRAW,0,0,tmp,400,300,true);
}

int main() {
  ioe_init(); // initialization for GUI
 int sec=1;
 has_kbd=io_read(AM_INPUT_CONFIG).present;
  while (1) {
    if(io_read(AM_TIMER_UPTIME).us%100000==0)
	{
    	 change(sec);
   	 draw();
   	 sec++;
	}
  }
  return 0;
}
