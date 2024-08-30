/*
================================================================================================================
Name: 22.c
Author: Abhishek Singh Sengar
Description:Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 29 Aug 2024
================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments\n");
	}
	int fd=open(argv[1],O_RDWR);
	int p=fork();
	char parent[15]="I am Parent";
	char child[15]="I am Child";
	if(p){
		write(fd,parent,sizeof(parent));
	}else{
		write(fd,child,sizeof(child));
	}
	return 0;
}

/*
================================================
Output: ./a.out temp.txt
	cat temp.txt
	I am ParentI am Child
================================================
*/


