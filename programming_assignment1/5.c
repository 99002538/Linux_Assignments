#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

	char line[1024];

	pid_t pid=fork();

	if(pid==0){

		printf("enter filename\n");

		gets(line);

		execl("/bin/gcc","gcc",line,NULL);

		exit(127);

	}

	else{

		waitpid(pid,0,0);

	}

	return 0;

	}

