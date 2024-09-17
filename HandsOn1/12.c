/*
===============================================================================
Name: 12.c
Author: Abhishek Singh Sengar
Description: Write a program to find out the opening mode of a file. Use fcntl.	    
Date: 22 Aug 2024
==============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
	if(argc<2){
		printf("invalid arguments");
	}
	int fd=open(argv[1],O_CREAT|O_RDWR);
	if(fd==-1){
		printf("error in opening file");
	}
	int dp=fcntl(fd,F_GETFL);
	if(dp==-1){
		printf("error in getting mode");
	}
	switch(dp){
		case 32768: printf("O_RDONLY");
			   break;
		case 32769: printf("O_WRONLY");
			   break;
		case 33793: printf("O_WRONLY|O_APPEND");
			   break;
		case 32770: printf("O_RDWR");
			   break;
		case 32794: printf("O_RDWR|O_APPEND");
			   break;
	}
	return 0;
}

/*
================================================
Output: ./a.out new.txt
	O_RDWR
================================================
*/

