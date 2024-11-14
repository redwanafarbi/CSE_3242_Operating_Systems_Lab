#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include <signal.h>

#define SIGNAL SIGUSR1

void signal_handler(int signal){
	if(signal == SIGNAL){
		printf("Thread2: Received Signal %d\n", signal);
	}
}

void* thread_fun_1(void* arg){
	pthread_t* thread2 = (pthread_t*)arg;
	
	printf("Thread1: Sending signal to Thread 2 (PID: %d, TID: %lu)\n", getpid(), *thread2);
	sleep(2);
	pthread_kill(*thread2, SIGNAL);
	printf("Thread1: Signal sent\n");
	
	return NULL;
}

void* thread_fun_2(void* arg){
	printf("Thread2: Waiting for signal (PID: %d, TID: %lu)\n",getpid(), pthread_self());
	
	struct sigaction sa;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	
	if(sigaction(SIGNAL, &sa, NULL) == -1){
		printf("Sigaction");
		pthread_exit(NULL);
	}
	
	while(1){
		pause();
	}
	
	return NULL ;
}


int main(){
	pthread_t thread1,thread2;
	
	//Thread creation
	if(pthread_create(&thread2, NULL, (void *)thread_fun_2, NULL) !=0 ){
		printf("Thread 2 creation unsuccessfull\n");
		exit(1);
	}
	
	if(pthread_create(&thread1, NULL, (void *)thread_fun_1, NULL) !=0 ){
		printf("Thread 1 creation unsuccessfull\n");
		exit(1);
	}
	
	// Waiting for threads to finish execution
	pthread_join(thread1, NULL);
	pthread_cancel(thread2);
	pthread_join(thread2, NULL);
	
	printf("Main thread: Exitting\n");
	
	exit(0);
}

