/*
========================================================================================================
Name : 31.b
Author : Abhishek Singh Sengar
Description : Write a program to create a semaphore and initialize value to the semaphore.
		b. Create a counting semaphore.
Date: 12 Sept, 2024.
========================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int main(){
	key_t key=ftok(".",2);
	if(key==-1){
		perror("error in ftok");
	}
	int sem_id=semget(key,1,IPC_CREAT|0777);
	if(sem_id==-1){
		perror("error in creating semaphore");
	}
	union semun{
		int val;
	}semaphore;
	semaphore.val=5;
	int status=semctl(sem_id,0,SETVAL,semaphore);
	if(status==-1){
		perror("error in initializing semaphore");
	}
	printf("counting semaphore created successfully\n");
	return 0;
}

/*
========================================================================================================
Output:

./a.out
counting semaphore created successfully

========================================================================================================
*/
