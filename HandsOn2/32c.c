/*
========================================================================================================
Name : 32.c
Author : Abhishek Singh Sengar
Description : Write a program to implement semaphore to protect any critical section.
		c. Protect multiple pseudo resources (may be two) using counting semaphore.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/sem.h>
int main(){
	char *file="./file.txt";
	int fd=open(file,O_CREAT|O_RDWR,0777);
	int data=10;
	if(fd==-1){
		perror("error in opening file");
	}
	union semun{
		int val;
	}semaphore;
	int key=ftok(".",19);
	int sem_id=semget(key,1,0);
	if(sem_id==-1){
		sem_id=semget(key,1,IPC_CREAT|0777);
		if(sem_id==-1){
			perror("error in creating semaphore");
		}
		semaphore.val=2;
        	semctl(sem_id,0,SETVAL,semaphore);
	}
	
	struct sembuf operation;
	operation.sem_num=0;
	operation.sem_flg=0;
	printf("press key to lock critical section");
	getchar();
	operation.sem_op=-1;
	int status=semop(sem_id,&operation,1);
	if(status==-1){
		perror("error in operating semaphore");
	}

	printf("critical section locked\n");
	int readdata=read(fd,&data,sizeof(data));
	if(readdata==-1){
		perror("error in reading data");
	}else if(readdata==0){
		printf("no data\n");
	}else{
		printf("data: %d\n",data);
	}
	
	printf("enter key to exit critical section");
	getchar();
	operation.sem_op=1;
	status=semop(sem_id,&operation,1);
	if(status==-1){
		perror("error in operating semaphore");
	}
	close(fd);
	return 0;
}

/*
========================================================================================================
Output:

./a.out
terminal 1:
press key to lock critical section
critical section locked
data: 55
enter key to exit critical section

terminal 2:
press key to lock critical section
critical section locked
data: 55
enter key to exit critical section

terminal 3:
press key to lock critical section



========================================================================================================
*/
