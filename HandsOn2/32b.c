/*
========================================================================================================
Name : 32.b
Author : Abhishek Singh Sengar
Description : Write a program to implement semaphore to protect any critical section.
		b. Protect shared memory from concurrent write access.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/sem.h>
#include<sys/shm.h>
int main(){
	union semun{
		int val;
	}semaphore;
	int key=ftok(".",19);
	int sem_id=semget(key,1,0);
	if(sem_id==-1){
		semget(key,1,IPC_CREAT|0777);
		semaphore.val=1;
        	semctl(sem_id,0,SETVAL,semaphore);
	}

	int shmkey=ftok(".",27);
	int size=20;
	int shm_id=shmget(shmkey,size,IPC_CREAT|0777);
	if(shm_id==-1){
		perror("error in getting shared memory");
	}
	char *shmpoint=shmat(shm_id,NULL,0);
	if(*shmpoint){
		perror("error while attaching address space");
	}

	struct sembuf operation;
	operation.sem_num=0;
	operation.sem_flg=0;
	printf("press key to lock critical section\n");
	getchar();
	operation.sem_op=-1;
	int status=semop(sem_id,&operation,1);
	if(status==-1){
		perror("error in operating semaphore");
	}
	printf("critical section locked\n");

	printf("write to shared memory\n");
	sprintf(shmpoint,"hii i am shared memory");
	printf("press key to read from shared memory\n");
	getchar();
	printf("%s\n",shmpoint);

	printf("enter key to exit critical section\n");
	getchar();
	operation.sem_op=1;
	status=semop(sem_id,&operation,1);
	if(status==-1){
		perror("error in operating semaphore");
	}
	return 0;
}


/*
========================================================================================================
Output:

./a.out
terminal 1:
error while attaching address space: Invalid argument
press key to lock critical section

error in operating semaphore: Invalid argument
critical section locked
write to shared memory
press key to read from shared memory

hii i am shared memory
enter key to exit critical section

terminal 2:
error while attaching address space: Success
press key to lock critical section



========================================================================================================
*/

