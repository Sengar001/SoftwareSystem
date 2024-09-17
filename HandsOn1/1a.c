/*
================================================
Name: 1a.c
Author: Abhishek Singh Sengar
Description: create the following types of file
	     a.softlink(symlink system call)
Date: 14 Aug 2024
================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	int count=symlink(argv[1],argv[2]);
	if(count==0){
		printf("successful");
	}else{
		printf("unsuccessful");
	}
	return 0;
}

/*
================================================
Output: gcc 1a.c
	./a.out soft.txt softlink
	successful
================================================
*/
