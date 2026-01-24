#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)
#define N  32
void __am_gpu_init() {  

}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  int h = inw(VGACTL_ADDR) ;
  int w = inw(VGACTL_ADDR + 2) ;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height =  h,
    .vmemsz = w * h * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {

    uint32_t i = 0;
    uint32_t j = 0;
    int fb_width = inw(VGACTL_ADDR + 2) ;
    int w = ctl->w;
    int h = ctl->h;
    uint32_t *src = (uint32_t *)ctl->pixels;
    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;

    for (j = 0; j < h; j++) {
      for (i = 0; i < w; i++) {
        int src_index = j * w + i;
        int dst_x = ctl->x + i;
        int dst_y = ctl->y + j;
        int dst_index = dst_y * fb_width + dst_x;
        fb[dst_index] = src[src_index];
      }
    }

  if (ctl->sync) {
    outw(SYNC_ADDR, 1);
  } else {
    outw(SYNC_ADDR, 0);
  }

}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
    status->ready = true;
}
