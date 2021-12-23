#include "memory.h"
#include "cpu.h"
#include "ppu.h"
#include "psg.h"

byte memory_readb(word address) {
  byte ret = 0;
  // switch (address >> 13) {
  //   case 0: return cpu_ram_read(address & 0x07FF);
  //   case 1: return ppuio_read(address);
  //   case 2: return psgio_read(address);
  //   case 3: return cpu_ram_read(address & 0x1FFF);
  //   default: return mmc_read(address);
  // }
  switch (address >> 13) {
    case 0: ret = cpu_ram_read(address & 0x07FF); break;
    case 1: ret = ppuio_read(address); break;
    case 2: ret = psgio_read(address); break;
    case 3: ret = cpu_ram_read(address & 0x1FFF); break;
    default: ret = mmc_read(address); break;
  }
  // if (ret)
  //   printf("[%u] memory_readb(%u) = %u\n", (address >> 13), address, ret);
  return ret;
}

void memory_writeb(word address, byte data) {
  // DMA transfer
  int i;
  if (address == 0x4014) {
    for (i = 0; i < 256; i++) {
      ppu_sprram_write(cpu_ram_read((0x100 * data) + i));
    }
    return;
  }
  switch (address >> 13) {
    case 0: return cpu_ram_write(address & 0x07FF, data);
    case 1: return ppuio_write(address, data);
    case 2: return psgio_write(address, data);
    case 3: return cpu_ram_write(address & 0x1FFF, data);
    default: return mmc_write(address, data);
  }
}

word memory_readw(word address) {
  return memory_readb(address) + (memory_readb(address + 1) << 8);
}

void memory_writew(word address, word data) {
  memory_writeb(address, data & 0xFF);
  memory_writeb(address + 1, data >> 8);
}
