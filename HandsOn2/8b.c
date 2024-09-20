/*
========================================================================================================
Name : 8.b
Author : Abhishek Singh Sengar
Description : Write a separate program using signal system call to catch the following signals.
		b. SIGINT
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
        signal(SIGINT,signalcaught);
        while(1){
	}
        return 0;
}


/*
========================================================================================================
Output:

./a.out
Press Ctrl+C to trigger SIGINT...
^C
SIGSEGV caught


========================================================================================================
*/

