/*
========================================================================================================
Name : 22
Author : Abhishek Singh Sengar
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
	char *name="./22-fifo";
	int f=mkfifo(name,0777);
	if(f==-1){
		perror("error in creating fifo file");
	}
	char buff[50]="hii this is me!";
	int fd=open(name,O_WRONLY);
	if(fd==-1){
		perror("error in opening file");
	}
	write(fd,&buff,sizeof(buff));
	close(fd);
	return 0;
}
