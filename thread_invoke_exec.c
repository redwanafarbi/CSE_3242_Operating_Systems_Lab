#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

// Thread 1
int thread_fun_1(){
	sleep(1);
	execlp("./test","Test",NULL);
}

// Thread 2
int thread_fun_2(){
	
	for(int k = 0;;k++){
		printf("Thread-2 PID: %d\n", getpid());
	}
}


int main(){
	pthread_t thread1,thread2;
	
	//Thread creation
	pthread_create(&thread1,NULL, (void *)thread_fun_1, NULL);
	pthread_create(&thread2,NULL, (void *)thread_fun_2, NULL);
	printf("Thread1 = %lu, Thread2 = %lu\n", thread1, thread2);
	
	// Waiting for threads to finish execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	exit(0);
}

