/*
============================================================================================
Name: 17a.c
Author: Abhishek Singh Sengar
Description:  Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 28 Aug 2024
============================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	if(argc!=2){
	printf("invalid arguments");
	}
	int fd=open(argv[1],O_WRONLY);
	int ticketno[1]={0};
	int w=write(fd,ticketno,1);
	printf("ticket window created\n");
	return 0;
}

/*
================================================
Output: ./a.out temp.txt
	ticket window created

================================================
*/

