/*
========================================================================================================
Name : 4
Author : Abhishek Singh Sengar
Description : Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A"(dst));
}

int main(){
	unsigned long long int start,end;
	start=rdtsc();
	for(int i=0;i<100;i++){
	getpid();
	}
	end=rdtsc();
	printf("time taken to execute getpid %lld\n",end-start);
}

/*
========================================================================================================
Output:

./a.out
time taken to execute getpid 52293


========================================================================================================
*/
