/*
================================================================================================================
Name: 25.c
Author: Abhishek Singh Sengar
Description:Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 29 Aug 2024
================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int p=fork();
	if(!p){
		sleep(5);
		printf("first child\n");
	}else{
		int q=fork();
		if(!q){
			sleep(10);
			printf("second child\n");
		}else{
			int r=fork();
			if(!r){
				sleep(15);
				printf("third child\n");
			}else{
				printf("enter parent wants to wait for child 1,2,3\n");
				int a;
				scanf("%d",&a);
				switch(a){
					case 1: printf("waiting for first child\n");
						waitpid(p,NULL,0);
						break;
					case 2: printf("waiting for second child\n");
						waitpid(q,NULL,0);
						break;
					case 3: printf("waiting for third child\n");
						waitpid(r,NULL,0);
						break;
				}
			}
		}
	}
	return 0;
}

/*
================================================
Output: ./a.out
	enter parent wants to wait for child 1,2,3
	2
	waiting for second child
	first child
	second child

================================================
*/

