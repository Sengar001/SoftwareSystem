/*
========================================================================================================
Name : 10.a
Author : Abhishek Singh Sengar
Description : Write a separate program using sigaction system call to catch the following signals.
		a. SIGSEGV
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void caught(){
    printf("SIGSEGV caught\n");
    exit(1);
}
int main(){
    	struct sigaction s;
	s.sa_handler=caught;
	s.sa_flags=0;
    	int p=sigaction(SIGSEGV,&s,NULL);
   	if(p==-1){
		 perror("Error");
    	}
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
