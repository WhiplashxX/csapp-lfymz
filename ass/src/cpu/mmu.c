#include"cpu/mmu.h"
#include"memory/dram.h"
#include<stdint.h>

uint64_t va2pa(uint64_t vaddr)
{
    return vaddr % MM_LEN;
}