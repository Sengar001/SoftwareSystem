/*
=========================================================================================================
Name: 18a.c
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
	struct ticket r;
	int fd=open(argv[1],O_RDWR);
	printf("enter window number for ticket booking 1 2 3\n");
	int p;
	scanf("%d",&p);
	lseek(fd,(p-1)*sizeof(struct ticket),SEEK_SET);
	struct flock fc;
	fc.l_type=F_WRLCK;
	fc.l_whence=SEEK_CUR;
	fc.l_start=0;
	fc.l_len=sizeof(struct ticket);
	int q=fcntl(fd,F_SETLKW,&fc);
	if(q==-1){
		printf("error");
	}
	read(fd,&r,sizeof(struct ticket));
	printf("window: %d\nticket sold: %d\n",r.window,r.ticket);
	r.ticket++;
	lseek(fd,(p-1)*sizeof(struct ticket),SEEK_SET);
	write(fd,&r,sizeof(struct ticket));
	printf("press enter for ticket booking\n");
	getchar();
	getchar();
	fc.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&fc);
	printf("window: %d\nyour ticket number: %d\n",r.window,r.ticket);
	return 0;
}

/*
================================================
Output: terminal 1
	./a.out ticket.txt
	enter window number for ticket booking 1 2 3
	2
	window: 2
	ticket sold: 3
	press enter for ticket booking

	terminal 2
	./a.out ticket.txt
	enter window number for ticket booking 1 2 3
	2

	terminal 3
	./a.out ticket.txt
	enter window number for ticket booking 1 2 3
	1
	window: 1
	ticket sold: 4
	press enter for ticket booking

	window: 1
	your ticket number: 5
================================================
*/

