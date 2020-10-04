#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(){

	int fd=open("a.txt",O_RDWR | O_CREAT);

	if(fd<0){

		perror("r1");

		exit(1);

	}
	char *c=(char *)calloc(100,sizeof(char));

	int sz=read(fd,c,10);

	int sz1=write(fd,c,10);
	
	close(fd);

	return 0;

}
