#include "common.h"
#include "fce.h"
#include "psg.h"

extern char rom_mario_nes[];

int main() {
  ioe_init();

  printf("ioe_init done!\n\n");

  printf("==================== LiteNES Emulator ====================\n\n");
  printf("Control:      [%s]         SELECT [%s]   START [%s]\n"
         "          [%s] [%s] [%s]          A [%s]   B     [%s]\n\n",
        TOSTRING(KEY_UP),   TOSTRING(KEY_SELECT), TOSTRING(KEY_START),
        TOSTRING(KEY_LEFT), TOSTRING(KEY_DOWN),   TOSTRING(KEY_RIGHT),
        TOSTRING(KEY_A),    TOSTRING(KEY_B));
  printf("==========================================================\n");

  assert(fce_load_rom((void *)rom_mario_nes) == 0);
  printf("Load done!\n");
  fce_init();
  printf("Init done!\n");
  fce_run();
  return 1;
}
