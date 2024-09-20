/*
========================================================================================================
Name : 2
Author : Abhishek Singh Sengar
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
void rlimit(int resource,char *name){
	struct rlimit r;
        int f=getrlimit(resource,&r);
	if(f==-1){
		perror("error in getrlimit\n");
	}
	printf("%s\n",name);
	printf("soft limit: %ld\n",r.rlim_cur);
	printf("hard limit: %ld\n",r.rlim_max);

}

int main(){
	rlimit(RLIMIT_CPU,"RLIMIT_CPU");
   	rlimit(RLIMIT_FSIZE,"RLIMIT_FSIZE");
    	rlimit(RLIMIT_DATA,"RLIMIT_DATA");
    	rlimit(RLIMIT_STACK,"RLIMIT_STACK");
    	rlimit(RLIMIT_CORE,"RLIMIT_CORE");
    	rlimit(RLIMIT_NOFILE,"RLIMIT_NOFILE");
   	rlimit(RLIMIT_AS,"RLIMIT_AS");
    	rlimit(RLIMIT_NPROC,"RLIMIT_NPROC");
    	rlimit(RLIMIT_MEMLOCK,"RLIMIT_MEMLOCK");
    	rlimit(RLIMIT_LOCKS,"RLIMIT_LOCKS,");
	return 0;
}


/*
========================================================================================================
Output:
RLIMIT_CPU
soft limit: -1
hard limit: -1
RLIMIT_FSIZE
soft limit: -1
hard limit: -1
RLIMIT_DATA
soft limit: -1
hard limit: -1
RLIMIT_STACK
soft limit: 8388608
hard limit: -1
RLIMIT_CORE
soft limit: 0
hard limit: -1
RLIMIT_NOFILE
soft limit: 1024
hard limit: 1048576
RLIMIT_AS
soft limit: -1
hard limit: -1
RLIMIT_NPROC
soft limit: 29978
hard limit: 29978
RLIMIT_MEMLOCK
soft limit: 991924224
hard limit: 991924224
RLIMIT_LOCKS,
soft limit: -1
hard limit: -1


==============================================================================================
==========

*/
