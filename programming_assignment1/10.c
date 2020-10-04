#include <stdio.h>

int send_signal(int pid) 
{

	int ret;

	ret=kill(pid,SIGHUP);

	printf("%d",ret);

}
