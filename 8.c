/*
==================================================================================================================
Name: 8.c
Author: Abhishek Singh Sengar
Descripion: Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 22 Aug 2024
===================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
	int count=open(argv[1],O_RDONLY);
	char arr[50];
	int ptr=0;
	while(1){
		int byte=read(count,&arr[ptr],1);
		if(byte==0){
			break;
		}
		if(arr[ptr]=='\n'){
			write(1,arr,ptr);
			getchar();
			ptr=0;
			continue;
		}
		ptr++;
	}
	close(count);
	return 0;
}

/*
================================================
Output: ./a.out line.txt
	his is line 1.
	This is line 2.
	This is line 3.
	This is line 4.
	This is line 5.

================================================
*/

