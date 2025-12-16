#include<stdio.h>
void print_bin(void *vp,int size);
int main(){
    unsigned char reg =5;
    unsigned char value1;
    unsigned char value2;
    value1=reg<<1;
    printf("first shift:");
    print_bin(&value1,sizeof(value1));
    value2=value1<<1;
    printf("second shift:");
    print_bin(&value2,sizeof(value2));
}
void print_bin(void *vp,int size)
{
    int i;
    for(i=size-1;i>=0;i--)
    {
        unsigned char mask=0x80;
        while(mask)
        {
            if(((*(char *)vp)+i)&mask)
            {
                printf("1");
            }else{
                printf("0");
            }
            mask>>=1;
        }
        printf(" ");
    }
    printf("\n");
}