/*
========================================================================================================
Name : 8.a
Author : Abhishek Singh Sengar
Description : Write a separate program using signal system call to catch the following signals.
		a. SIGSEGV
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalcaught(int sig){
	printf("SIGSEGV caught\n");
	exit(1);
}
int main(){
	signal(SIGSEGV,signalcaught);
	int *ptr=NULL;
	*ptr=1;
	return 0;
}

/*
========================================================================================================
Output:

./a.out
SIGSEGV caught


========================================================================================================
*/
