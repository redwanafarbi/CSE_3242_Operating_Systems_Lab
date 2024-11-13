#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int a = 50;


void summation(){
	for(int i = 1; i<=10000; i++){
		a=a+1;
		printf("%d, After Summation: %d\n",i,a);
	}
}

void subtraction(){
	for(int i = 1; i<=10000; i++){
		a=a-1;
		printf("%d, After subtraction: %d\n",i,a);
	}
}


int main(){
	pthread_t thread1,thread2;
	
	//Thread creation
	pthread_create(&thread1,NULL, (void *)summation, NULL);
	pthread_create(&thread2,NULL, (void *)subtraction, NULL);
	
	// Waiting for threads to finish execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	exit(0);
}

