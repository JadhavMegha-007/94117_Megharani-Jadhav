#include<stdio.h>
int main(){
    unsigned int reg = 0xABCD;
    unsigned int value;
    value=(reg>>0)&0x000F;
    printf("\nlower bit : %x",value);
    value=(reg>>4)&0x000F;
    printf("\nupper bits of lower bits:%x",value);
}