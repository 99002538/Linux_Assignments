#include <stdio.h>
#include <pthread.h>

#define MAX 100
#define max_threads 10

int a[MAX]={0,5,3,1,2};

int thread_part=0;

int max_num[max_threads]={0};

void *maximum(void* ptr){

	int i,num=thread_part++;

	int maxs=0;

	for(i=num*max_threads;i<(num+1)*max_threads;i++){

		if(a[i]>maxs){

			maxs=a[i];

		}

	max_num[num]=maxs;
	}

}


int main(){

	pthread_t threads;
	
	int maxs=0;

	int max_num[max_threads]={0};
	for(int i=0;i<max_threads;i++)
		pthread_create(&threads,NULL,max_num,(void*)NULL);

	for(int i=0;i<max_threads;i++)
		pthread_join(threads,NULL);
	
	for(int i=0;i<max_threads;i++){

		if(max_num[i]>maxs){

			maxs=max_num[i];

			}

	}

	printf("%d",maxs);

	return 0;

}

