#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int min, max, avg, a;
int *number;

// Minimum value calculate function
void mini(){
	min = number[0];
	for(int i = 1; i<a ; i++){
		if(min > number[i]){
			min = number[i];
		}
	}
}

// Maximum value calculate function
void maxi(){
	max = number[0];
	for(int i = 1; i<a ; i++){
		if(max < number[i]){
			max = number[i];
		}
	}
}

// Average value calculate function

void average(){
	int sum = 0;
	for(int i = 0; i<a ; i++){
		sum += number[i];
	}
	
	avg = sum/a ;
}


int main(){
	printf("Size of array: ");
	scanf("%d", &a);
	
	number = (int *)calloc(a, sizeof(int));
	
	printf("Enter array elements: ");
	for(int i=0; i<a; i++){
		scanf("%d", &number[i]);
	}
	
	pthread_t thread1,thread2,thread3;
	
	//Thread creation
	pthread_create(&thread1,NULL, (void *)mini, NULL);
	pthread_create(&thread2,NULL, (void *)maxi, NULL);
	pthread_create(&thread2,NULL, (void *)average, NULL); 
	
	// Waiting for threads to finish execution
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("A. The average value = %d\n",avg);
	printf("B. The minimum value = %d\n",min);
	printf("C. The maximum value = %d\n",max);
	
	exit(0);
}



