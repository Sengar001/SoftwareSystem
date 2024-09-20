/*
	  ========================================================================================================
	  Name : 13
	  Author : Abhishek Singh Sengar
	  Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
	  Date: 12 Sept, 2024.
	  ========================================================================================================
	  */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void caught(int sig){
	printf("SIGSTOP caught signal\n");
}
int main(){
	printf("process ID: %d\n",getpid());
	signal(SIGSTOP,caught);
	sleep(20);
	return 0;
}

/*
========================================================================================================
Output:

./a.out
process ID: 17143


========================================================================================================
*/
