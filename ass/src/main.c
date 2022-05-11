#include"cpu/register.h"
#include"memory/instruction.h"
#include<stdio.h>
#include<stdint.h>
#include"disk/elf.h"
#include"cpu/mmu.h"
#include"memory/dram.h"
int main(){

    init_handler_table();

    //init
    reg.rax = 0x12340000;
    reg.rbx = 0x555555555190;
    reg.rcx = 0x555555555190;
    reg.rdx = 0xabcd;
    reg.rsi = 0x7fffffffe158;
    reg.rdi = 0x1;
    reg.rbp = 0x7fffffffe060;
    reg.rsp = 0x7fffffffe040;
    reg.rip = (uint64_t)&program[11];


    write64bits_dram(va2pa(0x7fffffffe060),0x0);//rbp
    write64bits_dram(va2pa(0x7fffffffe058),0x0);
    write64bits_dram(va2pa(0x7fffffffe050),0xabcd);
    write64bits_dram(va2pa(0x7fffffffe048),0x12340000);
    write64bits_dram(va2pa(0x7fffffffe040),0x00000000);//rsp
    //uint64_t pa = va2pa(0x7fffffffe060);
    //printf("%lx\n",read64bits_dram(va2pa(0x7fffffffe050)));
    print_register();
    print_stack();


    //run inst
    for(int i=0;i<15;++i)
    {
        instruction_cycle();

        print_register();
        print_stack();
    }


    //verify
    int match = 1;
    match = match && (reg.rax == 0x1234abcd);
    match = match && (reg.rbx == 0x555555555190);
    match = match && (reg.rcx == 0x555555555190);
    match = match && (reg.rdx == 0xabcd);
    match = match && (reg.rsi == 0xabcd);
    match = match && (reg.rdi == 0x12340000);
    match = match && (reg.rbp == 0x7fffffffe060);
    match = match && (reg.rsp == 0x7fffffffe040);
    if(match==1)
    {
        printf("register matched\n");
    }
    else
    {
        printf("register not matched\n");
    }

    match = match && (read64bits_dram(va2pa(0x7fffffffe060)) == 0x0);//rbp
    match = match && (read64bits_dram(va2pa(0x7fffffffe058)) == 0x1234abcd);
    match = match && (read64bits_dram(va2pa(0x7fffffffe050)) == 0xabcd);
    match = match && (read64bits_dram(va2pa(0x7fffffffe048)) == 0x12340000);
    match = match && (read64bits_dram(va2pa(0x7fffffffe040)) == 0x0);//rsp
    if(match==1)
    {
        printf("memory matched\n");
    }
    else
    {
        printf("memory not matched\n");
    }

    return 0;
}

 

