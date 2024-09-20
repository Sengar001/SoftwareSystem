/*
========================================================================================================
Name : 31.a
Author : Abhishek Singh Sengar
Description : Write a program to create a semaphore and initialize value to the semaphore.
		a. Create a binary semaphore.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int main(){
	key_t key=ftok(".",1);
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
	semaphore.val=1;
	int status=semctl(sem_id,0,SETVAL,semaphore);
	if(status==-1){
		perror("error in initializing semaphore");
	}
	printf("binary semaphore created successfully\n");
	return 0;
}	

/*
========================================================================================================
Output:

./a.out
binary semaphore created successfully

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x010624ae 0          abhishek-s 777        1         
0x020624ae 1          abhishek-s 777        1         
0x130624ae 7          abhishek-s 777        1  

========================================================================================================
*/
