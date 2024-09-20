/*
========================================================================================================
Name : 27.a
Author : Abhishek Singh Sengar
Description : Write a program to receive messages from the message queue.
		a. With 0 as a flag
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
	struct msgbuf{
		long mtype;
	 	int temp;
	}data;
	data.mtype=2;
	data.temp=1000;
	int send=msgrcv(msg,&data,sizeof(data),data.mtype,0);
	if(send==-1){
		perror("error in sendinf message");
	}
	printf("received data %d\n",data.temp);
	return 0;
}

/*
========================================================================================================
Output:

./a
key 17179822
message queue id 2
received data 1000


========================================================================================================
*/
