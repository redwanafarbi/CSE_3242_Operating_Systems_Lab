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
	const char *text = "I am new in this file\n"; 
	int len = strlen(text);
	
	file = open("write_text_file.txt", O_RDWR | O_CREAT, 0666);
	
	if(file < 0){
		printf("Error opening file");
		return 1;
	}
	else{
		write(file,text,len);
		close(file);
	}
	
	return 0;
}
