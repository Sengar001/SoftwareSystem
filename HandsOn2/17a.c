/*
========================================================================================================
Name : 17.a
Author : Abhishek Singh Sengar
Description : Write a program to execute ls -l | wc.
		a. Use dup
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pipefd[2];
	int p=pipe(pipefd);
	if(p==-1){
		perror("error in creating pipe");
	}
	int f=fork();
	if(f==0){
		close(STDIN_FILENO);
		dup(pipefd[0]);
		close(pipefd[1]);
		execl("/usr/bin/wc","wc",NULL);
	}else{
		close(STDOUT_FILENO);
		dup(pipefd[1]);
		close(pipefd[0]);
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
