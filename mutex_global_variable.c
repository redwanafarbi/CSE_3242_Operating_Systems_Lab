#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg){
	for(int i = 0 ; i<1000; i++){
		pthread_mutex_lock(&lock); // Lock before accessing counter
		counter++;
		pthread_mutex_unlock(&lock); // Lock after accessing counter
	}
	
	return NULL;
}

int main(){
	pthread_t thread1, thread2;
	
	pthread_mutex_init(&lock, NULL); // Initialized mutex
	
	//Create two threads
	
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, increment, NULL);
	
	// Finish the threads
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("Counter value: %d\n",counter);
	pthread_mutex_destroy(&lock); // Destroy the mutex
	return 0;
}
