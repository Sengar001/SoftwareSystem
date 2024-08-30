/*
============================================================================================
Name: 17b.c
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
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments");
		return -1;
	}
	int fd=open(argv[1],O_RDWR);
	int ticket;
	read(fd,&ticket,1);
	printf("ticket sold = %d\n",ticket);
	struct flock fc;
	fc.l_type=F_WRLCK;
	fc.l_whence=SEEK_SET;
	fc.l_start=0;
	fc.l_len=0;
	int p=fcntl(fd,F_SETLKW,&fc);
	if(p==-1){
		printf("error");
	}
	lseek(fd,0,SEEK_SET);
	read(fd,&ticket,1);
	ticket++;
	lseek(fd,0,SEEK_SET);
	write(fd,&ticket,1);
	printf("press enter for ticket booking\n");
	getchar();
	fc.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&fc);
	printf("your ticket no. = %d\n",ticket);
	return 0;
}

/*
================================================
Output: terminal 1
	./a.out temp.txt
	ticket sold = 2
	press enter for ticket booking

	terminal 2
	./a.out temp.txt
	ticket sold = 3

	terminal 3
	./a.out temp.txt
	ticket sold = 4

	press enter for ticket booking
	your ticket no. = 5

================================================
*/

