#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int *fibonacci_seq;
int n;

// Generate fibonacci series
void generate_fibonacci(){
	if(n>0) fibonacci_seq[0] = 0 ;
	if(n>1) fibonacci_seq[1] = 1;
	
	for(int i = 2; i<n; i++){
		fibonacci_seq[i] = fibonacci_seq[i-1] + fibonacci_seq[i-2];
	}
}

int main(){
	printf("Enter number: ");
	scanf("%d",&n);
	
	fibonacci_seq = (int *)malloc(n * sizeof(int));
	
	pthread_t thread1;
	
	//Thread creation
	pthread_create(&thread1,NULL, (void *)generate_fibonacci, NULL);
	
	// Waiting for threads to finish execution
	pthread_join(thread1, NULL);
	
	printf("Fibonacci sequence: ");
	for(int k = 0; k<n ; k++){
		printf("%d ", fibonacci_seq[k]);
	}
	printf("\n");
	
	exit(0);

}
