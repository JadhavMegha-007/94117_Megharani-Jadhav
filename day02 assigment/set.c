#include<stdio.h>
#define bv(n)(1<<(n))
void print_bin(void *vp,int size);
int main()
{
    unsigned char reg1=0x2A;
   reg1=reg1|bv(4);
   printf("after the set bit=%X\n",reg1);
   printf("\nbinaty form:");
   print_bin(&reg1,sizeof(reg1));
   unsigned char reg2=0x2A;
   reg2=(reg2&~bv(1));
   printf("after the clear bit=%X\n",reg2);
   printf("\nbinaty form:");
   print_bin(&reg2,sizeof(reg2));
   unsigned char reg3=0x2A;
   reg3=(reg3^bv(5));
   printf("after the toggle bit=%X\n",reg3);
   printf("\nbinaty form:");
   print_bin(&reg3,sizeof(reg3));
   return 0;

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
