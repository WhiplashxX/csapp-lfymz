#ifndef dram_guard
#define dram_guard

#include<stdint.h>


#define MM_LEN 1000
uint8_t mm[MM_LEN];//physcial memory

//virtual address = 0x0 -> 0xffffffffffffffff
//physcial address = 000 -> 999

//mm[0x7fffffffe058 % MM_LEN];//简单起见取余

#endif