/*
=============================================================================================================
Name: 6.c
Author: Abhishek Singh Sengar
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 22 Aug 2024
=============================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	char arr[15];
	int int_put=read(0,arr,10);
	printf("%d",int_put);
	write(1,arr,sizeof(arr));
	return 0;
}

/*
================================================
Output: ./a.out
	abhishek
	abhishek
	9
================================================
*/

