/*
================================================================================================================
Name: 30.c
Author: Abhishek Singh Sengar
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 30 Aug 2024
================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int main(int argc,char *argv[]){
	if(argc!=4){
		printf("invalid arguments");
		return -1;
	}
	time_t start,end;
	struct tm *ending;
	time(&start);
	ending=localtime(&start);
	ending->tm_hour=atoi(argv[1]);
	ending->tm_min=atoi(argv[2]);
	ending->tm_sec=atoi(argv[3]);
	end=mktime(ending);
	int p=fork();
	if(p==0){
		setsid();
		do{
			time(&start);
		}while(difftime(end,start)>0);
		system("echo good morning");
	}else{
		exit(0);
	}
}

/*
================================================
Output: ./a.out 18 34 30
	good morning
================================================
*/

