#include<stdlib.h>
#include<stdint.h>

typedef struct CPUSTRUCT{
  union{
    uint64_t rax;
    uint32_t eax;
    uint16_t ax;
    struct{
      uint8_t al;
      uint8_t ah;
    };
  };
  
  uint64_t rbx;
  uint64_t rcx;
  uint64_t rdx;
  uint64_t rsi;
  uint64_t rdi;
  uint64_t rbp;
  uint64_t rsp;
  uint64_t rip;

}reg_t;

reg_t reg;

