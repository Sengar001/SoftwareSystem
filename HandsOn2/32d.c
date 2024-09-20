/*
========================================================================================================
Name : 32.d
Author : Abhishek Singh Sengar
Description : Write a program to implement semaphore to protect any critical section.
		d. Remove the created semaphore.
Date: 12 Sept, 2024.
========================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>
int main(){
	int key=ftok(".",19);
	if(key==-1){
		perror("error while ftok");
	}
	int sem_id=semget(key,1,IPC_CREAT|0777);
	if(sem_id==-1){
		perror("error while creating semaphore");
	}
	printf("press enter to delete the semaphore\n");
	getchar();
	int status=semctl(sem_id,0,IPC_RMID);
	if(status==-1){
		perror("error while deleting semaphore\n");
	}else{
		printf("semaphore deleted successfully\n");
	}
	return 0;
}

========================================================================================================
Output:

./a.out
press enter to delete the semaphore
    
semaphore deleted successfully

=======================================================================================================
*/
