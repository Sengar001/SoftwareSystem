/*
========================================================================================================
Name : 8.f
Author : Abhishek Singh Sengar
Description : Write a separate program using signal system call to catch the following signals.
		f. SIGVTALRM (use setitimer system call)
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
void signalcaught(int sig){
        printf("SIGVTALRM caught\n");
        exit(1);
}
int main(){
        signal(SIGVTALRM,signalcaught);
        struct itimerval time;
        time.it_value.tv_sec = 5;
        time.it_value.tv_usec = 0;
        time.it_interval.tv_sec = 0;
        time.it_interval.tv_usec = 0;
        int p=setitimer(ITIMER_VIRTUAL,&time,NULL);
        if(p==-1){
                perror("error in setitimer\n");
        }
        while(1){
	}
        return 0;
}

/*
========================================================================================================
Output:

./a.out
SIGVTALRM caught

========================================================================================================
*/
