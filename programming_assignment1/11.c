#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(){

	struct timeval start,end;

	gettimeofday(&start,NULL);

	sleep(3);

	gettimeofday(&end,NULL);

	printf("%zu\n",end.tv_sec-start.tv_sec);

	return 0;

}
