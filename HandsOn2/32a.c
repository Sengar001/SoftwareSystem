/*
========================================================================================================
Name : 32.a
Author : Abhishek Singh Sengar
Description : Write a program to implement semaphore to protect any critical section.
		a. Rewrite the ticket number creation program using semaphore.
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
	int data;
	if(fd==-1){
		perror("error in opening file");
	}
	union sem{
		int val;
	}semaphore;
	int key=ftok(".",19);
	int sem_id=semget(key,1,0);
	if(sem_id==-1){
		sem_id=semget(key,1,IPC_CREAT|0777);
	        semaphore.val=1;
        	int status=semctl(sem_id,0,SETVAL,semaphore);
        	if(status==-1){
                	perror("error in intializing semaphore");
       		}
		if(sem_id==-1){
            		perror("Error while creating semaphore!");
		}	
	}
	struct sembuf operation;
	operation.sem_num=0;
	operation.sem_flg=0;
	printf("press key to lock critical section");
	getchar();
	operation.sem_op=-1;
	int status1=semop(sem_id,&operation,1);
	if(status1==-1){
		perror("error in operating semaphore");
	}

	printf("critical section locked\n");
	int readdata=read(fd,&data,sizeof(data));
	if(readdata==-1){
		perror("error in reading data");
	}else if(readdata==0){
		data=1;
	}else{
		data+=1;
		lseek(fd,0,SEEK_SET);
	}
	int writedata=write(fd,&data,sizeof(data));
	if(writedata==-1){
		perror("error in writing data");
	}
	printf("your ticket number id %d\n",data);
	
	printf("enter key to exit critical section");
	getchar();
	operation.sem_op=1;
	int status2=semop(sem_id,&operation,1);
	if(status2==-1){
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
your ticket number id 54
enter key to exit critical section

terminal 2:
press key to lock critical section



========================================================================================================
*/
