#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock;

void* increment(void* arg){
	int* a = (int*)arg; // Cast the argument to an integer pointer
	
	for(int i = 0 ; i<1000; i++){
		pthread_mutex_lock(&lock); // Lock before modifying
		
		(*a)++;
		
		pthread_mutex_unlock(&lock); // Unlock after modifying
	}
	
	return NULL;
}

int main(){

	int value = 0;
	
	pthread_t thread1, thread2;
	pthread_mutex_init(&lock,NULL); // Initialized mutex
	
	//Create threads
	
	pthread_create(&thread1, NULL, increment, &value);
	pthread_create(&thread2, NULL, increment, &value);
	
	
	//Wait for threads to finish execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("Value of local variable: %d\n",value);
	pthread_mutex_destroy(&lock);
	return 0;
}
