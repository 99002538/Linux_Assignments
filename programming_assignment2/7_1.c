#include<stdio.h>
#include<stdlib.h>
#include<fcntrl.h>
#include<unistd.h>

int main()
{
	int f1,f2;

	f1=mkfifo("pipeA",0666);

	if(f1!=0){

		printf("pipe created!");
	}

	f2=mkfifo("pipeB",0666);

	if(f2!=0){

		printf("pipe created!");

	}
}
