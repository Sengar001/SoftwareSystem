/*
========================================================================================================
Name : 8.c
Author : Abhishek Singh Sengar
Description : Write a separate program using signal system call to catch the following signals.
		c. SIGFPE
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalcaught(int sig){
        printf("SIGFPE caught\n");
        exit(1);
}
int main(){
        signal(SIGFPE,signalcaught);
	int result=1/0;
        return 0;
}
  
/*
========================================================================================================
Output:

./a.out
SIGFPE caught


========================================================================================================
*/
