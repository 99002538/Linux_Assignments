#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

struct message{
	long msg_type;
	char msg[100];
}messager;

int main(){

	key_y mykey;

	mykey=ftok("a.txt",65);

	int id;

	id=msgget(mykey,0666|IPC_CREAT);

	msgrcv(id,&messager,sizeof(messager),0);

	printf("received!");

	return 0;
msgctl(id,IPC_RMID,NULL);
}
