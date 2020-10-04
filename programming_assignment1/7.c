#include <stdio.h>

#include <pthread.h>

#include <sched.h>

void* funct(void* inefe){

        printf("Hello world!");

}

int main(){

struct sched_param schedparam;

schedparam.sched_priority = 0;

pthread_attr_t attr;

pthread_t thread;

pthread_attr_init(&attr);
pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
pthread_attr_setschedpolicy(&attr, SCHED_RR);
pthread_attr_setschedparam(&attr, &schedparam);

pthread_create(&thread, &attr,funct,NULL);
pthread_join(thread,NULL);
pthread_attr_destroy(&attr);

	return 0;
}


