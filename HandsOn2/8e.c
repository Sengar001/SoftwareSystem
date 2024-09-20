/*
========================================================================================================
Name : 8.e
Author : Abhishek Singh Sengar
Description : Write a separate program using signal system call to catch the following signals.
		e. SIGALRM (use setitimer system call)
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
void signalcaught(int sig){
        printf("SIGALRM caught\n");
        exit(1);
}
int main(){
        signal(SIGALRM,signalcaught);
        struct itimerval time;
	time.it_value.tv_sec = 5;  
    	time.it_value.tv_usec = 0; 
    	time.it_interval.tv_sec = 0; 
	time.it_interval.tv_usec = 0; 
	int p=setitimer(ITIMER_REAL,&time,NULL);
	if(p==-1){
		perror("error in setitimer\n");
	}
        pause();
        return 0;
}

/*
========================================================================================================
Output:

./a.out
SIGALRM caught

========================================================================================================
*/
