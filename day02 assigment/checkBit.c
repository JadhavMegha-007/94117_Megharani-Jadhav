#include<stdio.h>
#define bv(n)(1<<(n))
int main()
{
    unsigned char reg=0x08;
    if(reg & bv(3))
    {
    printf("bit is set");
    }else{
        printf("bit is not set");
    }
    return 0;
}