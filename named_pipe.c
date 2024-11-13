#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

int main(){
	char *msg;
	char *pipePath;
	int pipeFlag,n;
	
	char buffer[100], str1[80];
	
	msg = "Insert a number: ";
	
	write(STDOUT_FILENO, msg, strlen(msg)+1);
	
	n= read(STDIN_FILENO, &buffer, sizeof(buffer));
	buffer[n] = '\0';
	
	pipePath = "/home/redwana/Desktop/Pipe";
	if(access(pipePath, F_OK) == 0){
	//pipe exists
	printf("Exists");
	}else{
		pipeFlag = pipe(pipePath);
		
		if(pipeFlag < 0){
			printf("Failed");
			
		}
	
		int fd1 = open(pipePath, O_WRONLY | O_CREAT); 
		write(fd1, &buffer, strlen(buffer));
		
		int fd2 = open(pipePath,O_RDONLY);
        n = read(fd2, &buffer, sizeof(buffer));
        buffer[n] = '\0';
        write(STDOUT_FILENO, str1, strlen(str1)+1);
		
	}
	
	return 0;
}
