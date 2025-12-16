#include<stdio.h>
#define bv(n) (1<<(n))
void print_bin(void *vp,int size);
int main()
{
    unsigned char reg=0XAA;
    unsigned char value;
    printf("Value before modification (Read):");
    print_bin(&reg,sizeof(reg));
    value=(reg>>2)& 0X07;
    printf("Value after modification (Read):");
    print_bin(&value,sizeof(value));
    printf("Value before modification (Write):");
    print_bin(&reg,sizeof(reg));
    reg=reg & ~(bv(2)|bv(3)|bv(4));
    reg |= (0b011 << 2);
    printf("Value after modification (Write):");
    print_bin(&reg,sizeof(reg));
}
void print_bin(void *vp,int size)
{
    int i;
    for(i=size-1;i>=0;i--)
    {
        unsigned char mask=0X80;
        while(mask)
        {
            if(((*(unsigned char *)vp)+i) & mask)
                printf("1");
            else
                printf("0");
            mask>>=1;
        }
        printf(" ");
    }
    printf("\n");
}