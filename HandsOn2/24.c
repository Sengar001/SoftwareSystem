/*
========================================================================================================
Name : 24
Author : Abhishek Singh Sengar
Description : Write a program to create a message queue and print the key and message queue id.
Date: 12 Sept, 2024.
========================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main(){
	key_t key=ftok("./23-fifo",1);
	if(key==-1){
		perror("ftok error");
	}
	int msg=msgget(key,IPC_CREAT|IPC_EXCL|0700);
	if(msg==-1){
		perror("msgget error");
	}
	printf("key %d\n",key);
	printf("message queue id %d\n",msg);
	return 0;
}

/*
========================================================================================================
Output:

./a.out
key 17196304
message queue id 0


========================================================================================================
*/
