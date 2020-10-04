#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main()
{
char str[256]="start";
int fifo_read,fifo_write;
while(strcmp(str,"end")!=0)
{
fifo_read=open("pipeA",O_RDONLY);
if(fifo_read<0)
   printf("\nError opening read pipe");
else
   {
   read(fifo_read,str,255*sizeof(char));
   close(fifo_read);
   printf("\n%s",str);
   }

fifo_write=open("pipeB",O_WRONLY);
if(fifo_write<0)
   printf("\nError opening write pipe");
else
   {
   printf("\nEnter text:\n");
   scanf("%s",str);
   write(fifo_write,str,255*sizeof(char));
   close(fifo_write);
   }
}
}
