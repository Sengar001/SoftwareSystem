/*
========================================================================================================
Name : 9
Author : Abhishek Singh Sengar
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void stop(int sig){
	printf("SIGINT is caught\n");
	exit(1);
}

int main(){
	__sighandler_t status;
	status=signal(SIGINT,SIG_IGN);
	if(status==SIG_ERR){
		perror("error while ignoring signal\n");
	}
	sleep(5);
	status=signal(SIGINT,SIG_DFL);
	if(status==SIG_ERR){
		perror("error while signal\n");
	}
        status=signal(SIGINT,stop);
        if(status==SIG_ERR){
                perror("error while signal\n");
        }
	while(1){
	}

	return 0;
}


/*
========================================================================================================
Output:

./a.out
^C^C^C^C
^CSIGINT is caught


========================================================================================================
*/
