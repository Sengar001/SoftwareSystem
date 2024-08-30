/*
=========================================================================================================
Name: 20.c
Author: Abhishek Singh Sengar
Description: Find out the priority of your running program. Modify the priority with nice command.
Date: 29 Aug 2024
==========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
int main(){
	int pri=getpriority(PRIO_PROCESS,0);
	printf("current priority %d\n",pri);
	int newpri=15;
	pri=nice(newpri);
	printf("new priority %d\n",pri);
	return 0;
}

/*
================================================
Output: ./a.out
	current priority 0
	new priority 15
================================================
*/

