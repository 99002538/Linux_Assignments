#include <sys/ipc.h>
#include<sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

//sender

struct message{

	char msg[100];

	long msg_type;

}messager;

int main(){key_t mykey;

int id;

mykey=ftok("a.txt",65);

id=msgget(mykey,0666|IPC_CREAT);

printf("enter message");

fgets(messager.msg,100,stdin);

msgsnd(messager.msg,&messager,sizeof(&messager),0);

printf("sent!");

}
