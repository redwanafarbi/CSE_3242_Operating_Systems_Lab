#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

// Thread 1
int thread_fun_1(){
	pid_t pid;
	pid = fork();
	
	if(pid<0){
		printf("Child creation unsuccessfull\n");
	}
	else if(pid == 0){
		for(int j = 0;;j++){
			printf("Child PID: %d\n", getpid());
		}
	}
	else{
		for(int j = 0;;j++){
			printf("Parent PID: %d\n", getpid());
		}
	}
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
	
	// Waiting for threads to finish execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	exit(0);
}
