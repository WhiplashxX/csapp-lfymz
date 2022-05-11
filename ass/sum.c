#include<stdint.h>

uint64_t sum(u_int64_t n)
{
    if(n == 0)
    {
        return n;
    }
    else 
    {
        return n + sum(n-1);
    }
}

int main()
{
    uint64_t a = sum(3);
    return a;
}