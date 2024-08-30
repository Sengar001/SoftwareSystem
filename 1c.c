/*
================================================
Name: 1c.c
Author: Abhishek Singh Sengar
Description: create the following types of file
	     c.FIFO(mknod system call)
Date: 10 Aug 2024
================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc,char *argv[]){
	int count=mknod(argv[1],0777,0);
	if(count==0){
		printf("successful");
	}else{
		printf("unsuccessful");
	}
	return 0;
}

/*
================================================
Output: gcc 1c.c
	./a.out fifo.txt
	successful
================================================
*/

