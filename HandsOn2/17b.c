/*
========================================================================================================
Name : 17.b
Author : Abhishek Singh Sengar
Description : Write a program to execute ls -l | wc.
		b. Use dup2
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
		close(pipefd[1]);
		dup2(pipefd[0],STDIN_FILENO);
		execl("/usr/bin/wc","wc",NULL);
	}else{
		close(STDOUT_FILENO);
		close(pipefd[0]);
		dup2(pipefd[1],STDOUT_FILENO);
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
