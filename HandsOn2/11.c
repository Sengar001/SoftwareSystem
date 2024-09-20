/*
========================================================================================================
Name : 11
Author : Abhishek Singh Sengar
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void stop(int sig){
	printf("SIGINT is caught\n");
	exit(0);
}

int main(){
	struct sigaction s;
	s.sa_handler=SIG_IGN;
	s.sa_flags=0;
        int p=sigaction(SIGINT,&s,NULL);
        if(p==-1){
                perror("error while sigaction\n");
        }
        sleep(10);
	s.sa_handler=SIG_DFL;
        int q=sigaction(SIGINT,&s,NULL);
        if(q==-1){
                perror("error while sigaction\n");
        }
	s.sa_handler=stop;
        p=sigaction(SIGINT,&s,NULL);
        if(p==-1){
                perror("error while sigaction\n");
        }
	while(1){
	}

        return 0;
}

/*
========================================================================================================
Output:
./a.out
^C^C^C
^CSIGINT is caught

========================================================================================================
*/
