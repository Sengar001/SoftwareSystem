/*
========================================================================================================
Name : 29
Author : Abhishek Singh Sengar
Description : Write a program to remove the message queue.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main(){
	key_t key=ftok(".",1);
	if(key==-1){
		perror("ftok error");
	}
	int msg=msgget(key,IPC_CREAT|0700);
	if(msg==-1){
		perror("msgget error");
	}
	printf("key %d\n",key);
	printf("message queue id %d\n",msg);
	int send=msgctl(msg,IPC_RMID,NULL);
	if(send==-1){
		perror("error in removing message queue");
	}else{
		printf("message queue is removed successfuly\n");
	}
	return 0;
}


/*
========================================================================================================
Output:

./a.out
key 17179822
message queue id 2
message queue is removed successfuly

========================================================================================================
*/
