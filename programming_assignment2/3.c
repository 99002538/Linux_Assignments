#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define BufferSize 5
#define MaxItems 5

int in=0,out=0;

int Buffer[BufferSize];

sem_t full,empty;

pthread_mutex_t mutex;

void* producer(void* pno){

	int item=0;

for(int i=0;i<MaxItems;i++){

	item=rand();
	sem_t wait(&full);
	mutex_t lock(&mutex);
	Buffer[in]=item;
	in=(in+1)%BufferSize;
	sem_t post(&full);
	mutex_t unlock(&mutex);

}

}

void* consumer(void* cno){

	for(int i=0;i<MaxItems;i++){
	sem_t wait(&empty);
	mutex_t lock(&mutex);

	item=Buffer[out];
	out=(out+1)%BufferSize;

	sem_t post(&empty);
	mutex_t unlock(&mutex);

	}

}

int main(){

	pthread_t pro[5],con[5];

	int a[5]={1,2,3,4,5};

	sem_init(&empty,0,BufferSize);
	sem_init(&full,0,0);

	pthread_mutex_init(&mutex,NULL);

	for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;

}

	
