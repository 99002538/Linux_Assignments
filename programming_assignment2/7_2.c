#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

	int fifo_write,fifo_read;

	fifo_write=open("pipeA",O_WRONLY);

	char[256] str="start";

	while(strcmp(str,"end")!=0)

	{
		write(fifo_write,str,255*sizeof(char));

		close(fifo_write);

	}

	fifo_read=open("pipeB",O_RONLY);

	if(fifo_read<0){

		printf("error!");

	}

	else{
		read(fifo_read,str,255*sizeof(char));
		close(fifo_read);
		printf("%s",str);

	}

	return 0;

}
