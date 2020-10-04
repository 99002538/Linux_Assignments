#include <pthread.h>
#include <sched.h>

#define NUM_THREADS 5

int main(int argc,char *argv[]){

	int i,scope;

	pthread_t tid[NUM_THREADS];

	pthread_attr_t attr;

	pthread_attr_init(&attr);

	if(pthread_attr_getscope(&attr,&scope)!=0)
		fprintf(stderr,"unable!");

	else{

		if(scope==PTHREAD_SCOPE_PROCESS)
			printf("PTHREAD_SCOPE_PROCESS");
		else if(scope==PTHREAD_SCOPE_SYSTEM)
			printf("PTHREAD_SCOPE_SYSTEM");
		else
			fprintf(stderr,"Illegal");

	}

	pthread_atte_setscope(&attr,PTHREAD_SCOPE_SYSTEM);

	for(int i=0;i<NUM_THREADS;i++)
		pthread_create(&tid[i],&attr,runner,NULL);

	for(int i=0;i<NUM_THREADS;i++)
		pthread_join(tid[i],NULL);

}

void *runner(void *param){

	pthread_exit(0);

}
