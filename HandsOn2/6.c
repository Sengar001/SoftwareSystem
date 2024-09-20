/*
========================================================================================================
Name : 6
Author : Abhishek Singh Sengar
Description : Write a simple program to create three threads.
Date: 12 Sept, 2024.
========================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void* work(void * argc){
	int id=*(int*)argc;
	printf("running thread is %d\n",id);
}
int main(){
	pthread_t th[3];
	int id[3];
	for(int i=0;i<3;i++){
		id[i]=i;
		int ph=pthread_create(&th[i],NULL,work,&id[i]);
		if(ph!=0){
			perror("error in thread create\n");
			exit(1);
		}
	}
	for(int i=0;i<3;i++){
		int j=pthread_join(th[i],NULL);
		if(j!=0){
			perror("error in join\n");
			exit(1);
		}
	}
	printf("all thread completed\n");
	return 0;
}

/*
========================================================================================================
Output:
running thread is 2
running thread is 0
running thread is 1
all thread completed

========================================================================================================
*/
