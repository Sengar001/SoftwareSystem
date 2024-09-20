/*
========================================================================================================
Name : 15
Author : Abhishek Singh Sengar
Description : Write a simple program to send some data from parent to the child process.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pipefd[2];
	char wr[30]="Hii child I am parent!";
	int p=pipe(pipefd);
	if(p==-1){
		printf("error in creating pipe\n");
	}
	int f=fork();
	if(f==0){
		char rw[30];
		int r=read(pipefd[0],&rw,sizeof(wr));
		if(r==-1){
			printf("error on reading\n");
		}
		write(1,&rw,sizeof(rw));
	}else{
		int w=write(pipefd[1],&wr,sizeof(wr));
		if(w==-1){
			printf("error on writing\n");
		}
	}
}

/*
========================================================================================================
Output:

./a.out
Hii child I am parent!

========================================================================================================
*/
