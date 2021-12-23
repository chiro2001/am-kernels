#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#define MMIO_BASE 0xa0000000
#define FB_ADDR (MMIO_BASE + 0x1000000)

extern uint32_t image[][200][400];

#include "../typing-game/font.c"

#define FPS 30
#define CPS 5
#define CHAR_W 8
#define CHAR_H 16
#define NCHAR 128
#define COL_WHITE 0xeeeeee
#define COL_RED 0xff0033
#define COL_GREEN 0x00cc33
#define COL_PURPLE 0x2a0a29

enum { WHITE = 0, RED, GREEN, PURPLE };
uint32_t texture[3][26][CHAR_W * CHAR_H], blank[CHAR_W * CHAR_H];

void display_image(void *p, int x, int y, int w, int h) {
  io_write(AM_GPU_FBDRAW, x, y, p, w, h, true);
}

int main() {
  unsigned long last = 0;
  unsigned long current;
  ioe_init();
  for (int ch = 0; ch < 26; ch++) {
    char *c = &font[CHAR_H * ch];
    for (int i = 0, y = 0; y < CHAR_H; y++)
      for (int x = 0; x < CHAR_W; x++, i++) {
        int t = (c[y] >> (CHAR_W - x - 1)) & 1;
        // int t = (c[y] << (CHAR_W - x - 1)) & 0x80;
        texture[WHITE][ch][i] = t ? COL_WHITE : COL_PURPLE;
        texture[GREEN][ch][i] = t ? COL_GREEN : COL_PURPLE;
        texture[RED][ch][i] = t ? COL_RED : COL_PURPLE;
      }
  }
  for (int j = 0; j < 16; j++) {
      for (int i = 0; i < 8; i++) {
        *((uint32_t *)texture[GREEN][1] + j * 400 + i) =
            ((font[10 * 16 + j] << i) & 0x80) ? COL_GREEN : COL_PURPLE;
      }
    }
  printf("Init done!\n");
  while (1) {
    current = io_read(AM_TIMER_UPTIME).us;
    printf("Dsiplaying... FPS = %d\n", 100000 / (current - last));
    last = current;
    display_image(image, 0, 50, 400, 200);
    // display_image(font, 100, 20, 8, 16);
    // display_image(image, 100, 0, 8, 16);
    for (int j = 0; j < 16; j++) {
      for (int i = 0; i < 8; i++) {
        *((uint32_t *)FB_ADDR + j * 400 + i) =
            ((font[10 * 16 + j] << i) & 0x80) ? 0xFFFFFFFF : 0x0;
      }
    }
    display_image(texture[GREEN][2], 0, 200, CHAR_W, CHAR_H);
    // io_write(AM_GPU_FBDRAW, 0, 200, texture[GREEN][1], CHAR_W, CHAR_H, false);
  }
  return 0;
}
