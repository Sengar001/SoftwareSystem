/*
==========================================================
Name: 24.c
Author: Abhishek Singh Sengar
Description:Write a program to create an orphan process.
Date: 29 Aug 2024
=========================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
	int c=fork();
	if(c){
		sleep(5);
	}else{
		printf("ppid before orphan %d\n",getppid());
		sleep(10);
		printf("ppid after ophan %d\n",getppid());
	}
	return 0;
}

/*
================================================
Output: ./a.out 
	ppid before orphan 4214

	ppid after ophan 1662
================================================
*/

