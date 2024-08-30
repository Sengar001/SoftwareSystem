/*
=========================================================================================================
Name: 21.c
Author: Abhishek Singh Sengar
Description: Write a program, call fork and print the parent and child process id.
Date: 29 Aug 2024
==========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
	int c=fork();
	if(c){
		printf("parent pid %d\n",getpid());
	}else{
		printf("child pid %d\n",getpid());
	}
	return 0;
}

/*
================================================
Output: ./a.out
	parent pid 4913
	child pid 4914
================================================
*/

