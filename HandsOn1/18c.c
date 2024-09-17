
/*
=========================================================================================================
Name: 18b.c
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
	printf("enter window number for checking ticket 1 2 3\n");
	int p;
	scanf("%d",&p);
	lseek(fd,(p-1)*sizeof(struct ticket),SEEK_SET);
	struct flock fc;
	fc.l_type=F_RDLCK;
	fc.l_whence=SEEK_CUR;
	fc.l_start=0;
	fc.l_len=sizeof(struct ticket);
	int q=fcntl(fd,F_SETLKW,&fc);
	if(q==-1){
		printf("error");
	}
	read(fd,&r,sizeof(struct ticket));
	printf("window: %d\nticket sold: %d\n",r.window,r.ticket);
	printf("press enter to release lock\n");
	getchar();
	getchar();
	fc.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&fc);
	printf("lock released\n");
	return 0;
}

/*
=======================================================
Output: ./a.out ticket.txt
	enter window number for checking ticket 1 2 3
	1
	window: 1
	ticket sold: 5
	press enter to release lock
            
	lock released

=======================================================
*/

