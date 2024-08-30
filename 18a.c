/*
=========================================================================================================
Name: 18.c
Author: Abhishek Singh Sengar
Description: Write a program to perform Record locking.
		a. Implement write lock
		b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28 Aug 2024
==========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments");
		return -1;
	}
	struct ticket{
		int window;
		int ticket;
	};
	struct ticket t1={1,2};
	struct ticket t2={2,3};
	struct ticket t3={3,4};
	struct ticket buffer[3];
	buffer[0]=t1;
	buffer[1]=t2;
	buffer[2]=t3;
	int fd=open(argv[1],O_WRONLY);
	write(fd,&buffer,sizeof(buffer));
	printf("ticket windows created\n");
	return 0;
}

/*
================================================
Output: ./a.out ticket.txt
	ticket windows created

================================================
*/

