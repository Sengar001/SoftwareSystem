/*
========================================================================================================
Name : 18
Author : Abhishek Singh Sengar
Description : Write a program to find out total number of directories on the pwd. Execute ls -l | grep ^d | wc. Use only dup2.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pipefd1[2],pipefd2[2];
	int p1=pipe(pipefd1);
	if(p1==-1){
		perror("error in creating pipe");
	}
	int p2=pipe(pipefd2);
        if(p2==-1){
                perror("error in creating pipe");
        }
	int f=fork();
	if(f==0){
		close(STDIN_FILENO);
		close(pipefd2[1]);
		close(pipefd1[1]);
		close(pipefd1[0]);
		dup2(pipefd2[0],STDIN_FILENO);
		execl("/usr/bin/wc","wc",NULL);
	}else{
		int z=fork();
		if(z==0){
			close(pipefd1[1]);
			close(pipefd2[0]);
			close(STDIN_FILENO);
			dup2(pipefd1[0],STDIN_FILENO);
			close(STDOUT_FILENO);
			dup2(pipefd2[1],STDOUT_FILENO);
			execl("/usr/bin/grep","grep ^d","^d",NULL);

		}else{
			close(STDOUT_FILENO);
			close(pipefd1[0]);
			close(pipefd2[1]);
			close(pipefd2[0]);
			dup2(pipefd1[1],STDOUT_FILENO);
			execl("/usr/bin/ls","ls -l","-l",NULL);
		}
	}
	return 0;
}

/*
========================================================================================================
Output:

./a.out
      0       0       0

========================================================================================================
*/
