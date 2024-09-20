/*
========================================================================================================
Name : 23
Author : Abhishek Singh Sengar
Description : Write a program to print the maximum number of files that can be opened within a process and size of a pipe (circular buffer).
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
	char *name="./23-fifo";
	int f=mkfifo(name,0777);
	if(f==-1){
		perror("error in mkfifo");
	}
	long maxi=sysconf(_SC_OPEN_MAX);
	if(maxi==-1){
		perror("error in sysconf");
	}else{
		printf("maximum number of file can be opened %ld\n",maxi);
	}
	long size=pathconf(name,_PC_PIPE_BUF);
	if(size==-1){
		perror("error in pathconf");
	}else{
		printf("size of pipe %ld\n",size);
	}
	return 0;
}


/*
========================================================================================================
Output:

./a.out
maximum number of file can be opened 1024
size of pipe 4096


========================================================================================================
*/
