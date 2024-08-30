/*
================================================================================================================
Name: 23.c
Author: Abhishek Singh Sengar
Description: Write a program to create a Zombie state of the running program.
Date: 29 Aug 2024
================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
	int c=fork();
	if(c){
		sleep(100);
		printf("parent process pid=%d\n",getpid());
		printf("child pid=%d\n",c);
	}
	else{
		printf("child process pid=%d\n",getpid());
		printf("parent pid=%d\n",getppid());
	}
	return 0;
}

/*
================================================
Output: ./a.out 
	child process pid=4159
	parent pid=4158
	parent process pid=4158
	child pid=4159
================================================
*/

