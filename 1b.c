/*
================================================
Name: 1b.c
Author: Abhishek Singh Sengar
Description: create the following types of file
	     b.hardlink(link system call)
Date: 10 Aug 2024
================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	int count=link(argv[1],"hardlink");
	if(count==0){
		printf("successful");
	}
	else{
		printf("unsuccessful");
	}
	return 0;
}

/*
================================================
Output: gcc 1b.c
	./a.out temp.txt
	successful
================================================
*/
