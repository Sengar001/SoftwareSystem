/*
========================================================================================================
Name : 22
Author : Abhishek Singh Sengar
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/time.h>
int main(){
	char buff[50];
	struct timeval time;
	int fd=open("./22-fifo",O_RDONLY);
	if(fd==-1){
		perror("error in opening file");
	}
	time.tv_sec=10;
	time.tv_usec=10;
	fd_set rfds;
	FD_ZERO(&rfds);
	FD_SET(fd,&rfds);
	int ret=select(fd+1,&rfds,NULL,NULL,&time);
	if(ret==-1){
		perror("error in select");
	}else if(ret==0){
		printf("no data available within 10 sec\n");
	}else{
		read(fd,&buff,50);
		printf("data is recieved\n");
		write(1,&buff,sizeof(buff));
	}
	return 0;
}


/*
========================================================================================================
Output:

./a.out
data is recieved
hii this is me!

========================================================================================================
*/
