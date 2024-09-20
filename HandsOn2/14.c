/*
========================================================================================================
Name : 14
Author : Abhishek Singh Sengar
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pipefd[2];
	char wr[10]="hello!";
	int p=pipe(pipefd);
	if(p==-1){
		printf("error on creating pipe\n");
	}
	int w=write(pipefd[1],&wr,sizeof(wr));
	if(w==-1){
		printf("error on writing to pipe\n");
	}
	char rw[10];
	int r=read(pipefd[0],&rw,sizeof(wr));
	if(r==-1){
		printf("error on reading from pipe\n");
	}
	write(1,&rw,sizeof(rw));
	return 0;
}


/*
========================================================================================================
Output:

./a.out
hello!

========================================================================================================
*/
