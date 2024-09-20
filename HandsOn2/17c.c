/*
========================================================================================================
Name : 17.c
Author : Abhishek Singh Sengar
Description : Write a program to execute ls -l | wc.
		c. Use fcntl
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int pipefd[2];
	int p=pipe(pipefd);
	if(p==-1){
		perror("error in creating pipe");
	}
	int f=fork();
	if(f==0){
		close(STDIN_FILENO);
		close(pipefd[1]);
		fcntl(pipefd[0],F_DUPFD,STDIN_FILENO);
		execl("/usr/bin/wc","wc",NULL);
	}else{
		close(STDOUT_FILENO);
		close(pipefd[0]);
		fcntl(pipefd[1],F_DUPFD,STDOUT_FILENO);
		execl("/usr/bin/ls","ls","-l",NULL);
	}
	return 0;
}


/*
========================================================================================================
Output:

./a.out
     62     551    5116


========================================================================================================
*/
