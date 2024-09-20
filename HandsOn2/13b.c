/*
========================================================================================================
Name : 13
Author : Abhishek Singh Sengar
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 12 Sept, 2024.
========================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
	int pid=atoi(argv[1]);
	int kill1=kill(pid,SIGSTOP);
        if(kill1==0){
		printf("error in sending signal\n");
	}
       	return 0;
}
