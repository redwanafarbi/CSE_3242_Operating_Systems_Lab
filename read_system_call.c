#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	int file;
	char buf[1000];
	
	// Open and Read
	file = open("text_file.txt", O_RDONLY);
	
	if(file<0){
		printf("Error opening file");
		return 1;
	}
	else{
		read(file,buf,1000);
		buf[1000] = '\0';
		printf("Read from file: %s\n",buf);
	}
	
	close(file);
	
	return 0;
}
