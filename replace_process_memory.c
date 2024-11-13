#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <unistd.h>


int main(){
	pid_t child_pid, parent_pid;
	
	parent_pid = getpid();
	child_pid = fork();
	
	if(child_pid < 0){
		printf("Child creation unsuccessfull\n");
		exit(1);
	}
	
	else if(child_pid == 0){
		printf("Child creation successfull\n");
		printf("Child ID: %d\n",child_pid);
		
		for(int i = 1; i<=5 ; i++){
			printf("I = %d\n",i);
		}
		
		execlp("./test","test",NULL);
		
		for(int i = 6; i<=10 ; i++){
			printf("I = %d\n",i);
		}
	}
	
	else{
		printf("Parent Process\n");
	}
}
