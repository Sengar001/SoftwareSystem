#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include "./21-header.h"
int main(){
	char send[50]="sending data from 21a to 21b";
	char recv[50];
	init();
	int fd1=open(file1,O_WRONLY);
	if(fd1==-1){
		perror("error in opening file");
	}
	int fd2=open(file2,O_RDONLY);
	if(fd2==-1){
		perror("error in opening file");
	}
	write(fd1,&send,sizeof(send));
	read(fd2,&recv,50);
	write(1,&recv,sizeof(recv));
	close(fd1);
	close(fd2);
	return 0;
}
