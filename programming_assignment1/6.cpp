#include <iostream>
#include <pthread.h>

#define MAX 100 
#define MAX_THREADS 10

using namespace std;

int part=0;

int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };

int sum[10]={0};

void* sum_array(void *args){
        
        int thread_part=part++;
        
        for(int i=thread_part*(MAX/MAX_THREADS);i<(thread_part+1)*(MAX/MAX_THREADS);i++){
                
                sum[i]+=a[i];
                
        }       
        
}       

int main(){
        
 pthread_t threads[MAX_THREADS];
 
 for(int i=0;i<MAX_THREADS;i++){
         
         pthread_create(&threads[i],NULL,sum_array,(void*)NULL);
         
 }       
 
 for(int i=0;i<MAX_THREADS;i++){
         
         pthread_join(threads[i],NULL);
         
 }       
 
 int totalsum=0;

 for(int i=0;i<MAX_THREADS;i++){
        totalsum+=sum[i];
        
 }      
 
        cout<<totalsum<<endl;
        
return 0;

}
