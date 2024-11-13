#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid, myPID;
	
	pid = fork();
	
	if(pid < 0){
		printf("Child creation faild\n");
		exit(1);
	}
	
	else if(pid == 0){ 
		// Child Process
		printf("Child process creation successful\n");
		
		myPID = getpid();
		printf("Child ID: %d\n",myPID);
	}
	
	else{
		// Parent Process
		printf("Parent Process ID: %d\n", getpid());
		sleep(20);
	}
}




