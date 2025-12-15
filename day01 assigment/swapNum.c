#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter value of x and y:");
    scanf("%d%d",&x,&y);
    printf("Before swap\n");
    printf("x=%d    y=%d",x,y);
    x=x^y;
    y=x^y;
    x=x^y;
    printf("\nAfter swap\n");
    printf("x=%d    y=%d",x,y);
}