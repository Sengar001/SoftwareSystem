/*
==========================================================
Name: 16b.c
Author: Abhishek Singh Sengar
Description: Write a program to perform mandatory locking.
		b. Implement read lock
Date: 27 Aug 2024
=========================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/file.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments");
		return -1;
	}
	struct flock fc;
	fc.l_type=F_RDLCK;
	int fd=open(argv[1],O_RDONLY);
	int p=fcntl(fd,F_SETLKW,&fc);
	if(p==-1){
		printf("error");
	}
	printf("lock acquired\n");
	printf("press enter to release lock\n");
	getchar();
	fc.l_type=F_UNLCK;
	p=fcntl(fd,F_SETLK,&fc);
	if(p==-1){
		printf("error");
	}
	printf("lock released\n");
	return 0;
}

/*
================================================
Output: terminal 1
	./a.out temp.txt
	lock acquired
	press enter to release lock

	lock released

================================================
*/

