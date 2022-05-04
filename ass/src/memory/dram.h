#ifndef dram_guard
#define dram_guard

#include<stdint.h>
#include<stdio.h>
#include"cpu/register.h"
#include"cpu/mmu.h"


#define MM_LEN 1000
uint8_t mm[MM_LEN];//physcial memory

uint64_t read64bits_dram(uint64_t paddr);
void write64bits_dram(uint64_t paddr,uint64_t data);
void print_register();
void print_stack();

//virtual address = 0x0 -> 0xffffffffffffffff
//physcial address = 000 -> 999

//mm[0x7fffffffe058 % MM_LEN];//简单起见取余

#endif