/*
========================================================================================================
Name : 12
Author : Abhishek Singh Sengar
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
int main(){
	int child;
	child=fork();
	if(child==0){
		printf("%d child PID\n",getpid());
		printf("%d parent PID\n",getppid());
		sleep(5);
		int kill1=kill(getppid(),SIGKILL);
		if(kill1==0){
			printf("parent killed\n");
			sleep(5);
			printf("child exist\n");
		}else{
			printf("error in killing parent\n");
		}
	}else{
		while(1);
	}
	return 0;
}

/*
========================================================================================================
Output:
./a.out
17098 child PID
17097 parent PID
parent killed
Killed

child exist


========================================================================================================
*/
