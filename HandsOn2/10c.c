/*
========================================================================================================
Name : 10.c
Author : Abhishek Singh Sengar
Description : Write a separate program using sigaction system call to catch the following signals.
		c. SIGFPE
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void caught(){
    printf("SIGFPE caught\n");
    exit(1);
}
int main(){
        struct sigaction s;
        s.sa_handler=caught;
        s.sa_flags=0;
        int p=sigaction(SIGFPE,&s,NULL);
        if(p==-1){
                 perror("Error");
        }
        int a=1/0;
        return 0;
} 


/*
========================================================================================================
Output:
./a.out
SIGFPE caught


========================================================================================================
*/
