/*
========================================================================================================
Name : 1.c
Author : Abhishek Singh Sengar
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
 		c. ITIMER_PROF
Date: 12 Sept, 2024.
========================================================================================================
*/


#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void signalhandler(){
        printf("time expired\n");
        exit(0);
}

int main(){
        signal(SIGPROF,signalhandler);
        struct itimerval time;
        time.it_interval.tv_sec=0;
        time.it_interval.tv_usec=0;
        time.it_value.tv_sec=10;
        time.it_value.tv_usec=10;
        int f=setitimer(ITIMER_PROF,&time,NULL);
        if(f==-1){
                perror("error in setitimer\n");
        }
        while(1){
	}
}

/*
========================================================================================================
Output:
./a.out
Timer expired

==============================================================================================
==========

*/

