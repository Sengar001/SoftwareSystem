/*
================================================================================================================
Name: 26b.c
Author: Abhishek Singh Sengar
Description:Write a program to execute an executable program.
		b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 29 Aug 2024
================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	if(argc!=2){
		printf("invalid arguments\n");
	}
	execl(argv[1],argv[2],NULL);
	return 0;
}

/*
=================================================================================
Output: ./a.out b.out
10.c   14.c   18a.c  1c.c  25.c   27d.c  3.c  9.c      fifo.txt        softlink
11a.c  15.c   18b.c  20.c  26a.c  27e.c  4.c  a.out    File1	       soft.txt
11b.c  16a.c  18c.c  21.c  26b.c  28.c	 5.c  b.out    filedescriptor  t2.txt
11c.c  16b.c  19.c   22.c  27a.c  29.c	 6.c  dup.txt  hardlink        temp.txt
12.c   17a.c  1a.c   23.c  27b.c  2.c	 7.c  f1.txt   line.txt        ticket.txt
13.c   17b.c  1b.c   24.c  27c.c  30.c	 8.c  f2.txt   new.txt
=================================================================================
*/

