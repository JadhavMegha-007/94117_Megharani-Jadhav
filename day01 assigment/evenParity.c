#include<stdio.h>
int main()
{
    char x[10];
    int i,count;
   printf("enter the number");
   scanf("%s",&x);
   for(i=0;x[i]!='\0';i++)
   {
    if(x[i]=='1')
    count++;
   }
   if(count%2==0)
   {
    printf("even parity");
   }else{
    printf("odd parity");
       i=0;
            if(x[i]=='0')
                x[i]='1';
            else
                x[i]='0';
            printf("MSB bit is changed\n");
            for(i=0;x[i]!='\0';i++)
            {
                printf("%c",x[i]);
            }
        }
    
   }
