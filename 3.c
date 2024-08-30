/*
===========================================================================================================
Name: 3.c
Author: Abhishek Singh Sengar
Description: Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 14 Aug 2024
===========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int count=creat("filedescriptor",0755);
	printf("%d\n",count);
	return 0;
}

/*
================================================
Output: ./a.out
	3
================================================
*/

