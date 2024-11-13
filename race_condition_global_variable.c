#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

int counter = 0; // Global Varibable

void* increment(void* arg){
	for(int i = 0 ; i<1000; i++){
		counter++;
	}
	
	return NULL;
}


int main(){
	pthread_t thread1, thread2, thread3;
	
	//Create three threads
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, increment, NULL);
	pthread_create(&thread3, NULL, increment, NULL);
	
	// Wait for threads to finish their execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	
	printf("Counter value: %d\n", counter);
	return 0;
}
