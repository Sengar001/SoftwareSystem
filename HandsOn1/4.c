/*
================================================================================================
Name: 4.c
Author: Abhishek Singh Sengar
Description: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 10 Aug 2024
================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int count=open("File1",O_CREAT|O_EXCL,O_RDWR);
	if(count!=-1){
		printf("File Open Successful");
	}else{
		printf("Unsuccessful");
	}
	return 0;
}

/*
================================================
Output: ./a.out 
	File Open Successful
================================================
*/


