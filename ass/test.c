#include<stdio.h>

int main()
{
    union test
    {
        unsigned long a;
        unsigned char b[8];
    }t;
    t.a = 0x12345678;
    printf("%x,%x,%x,%x,%x,%x,%x,%x\n",t.b[0],t.b[1],t.b[2],t.b[3],t.b[4],t.b[5],t.b[6],t.b[7]);
}