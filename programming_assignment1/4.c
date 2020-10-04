#include <unistd.h>

#include <readline/readline.h>
#include<string.h>
#include <sys/wait.h>

#include <stdlib.h>

#include <stdio.h>

char **get_input(char *input);

int main(){

	char **command;

	char *input;

	int stat_loc;

	pid_t child_pid;

	while(1){
			
		input=readline("> ");
		command=get_input(input);

		child_pid=fork();

	if(child_pid==0){

	execvp(command[0],command);

printf("this shouldnt print");

	}

	else{

		waitpid(child_pid,&stat_loc,WUNTRACED);

	}

	}

	free(command);
	free(input);

	return 0;

}

char **get_input(char *input){

	char **command=malloc(8*sizeof(char));

	char *separator=" ";

	char *parser;

	int index=0;

	parser=strtok(input,separator);

	while(parser!=NULL){

		command[index]=parser;
		index++;

		parser=strtok(NULL,separator);

	}

	command[index]=NULL;

	return command;

}


