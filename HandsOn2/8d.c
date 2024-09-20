/*
========================================================================================================
Name : 8.d
Author : Abhishek Singh Sengar
Description : Write a separate program using signal system call to catch the following signals.
		d. SIGALRM (use alarm system call)
Date: 12 Sept, 2024.
========================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalcaught(int sig){
        printf("SIGALRM caught\n");
        exit(1);
}
int main(){
        signal(SIGALRM,signalcaught);
        alarm(5);
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
