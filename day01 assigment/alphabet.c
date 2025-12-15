#include<stdio.h>
int main(){
    char x;
    printf("enter the number");
    scanf("%c",&x);
    if((x>='A'&&x<='z')||(x>='a'&&x<='z'))
    {
        printf("alphabets are present");
        int y=x^32;
        printf("%d",&y);
    }else{
        printf("alphabets are not present");
    }
}