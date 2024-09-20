/*
========================================================================================================
Name : 30.a
Author : Abhishek Singh Sengar
Description : Write a program to create a shared memory.
		a. write some data to the shared memory
		b. attach with O_RDONLY and check whether you are able to overwrite.
		c. detach the shared memory
		d. remove the shared memory
Date: 19 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
	key_t key=ftok(".",1);
	ssize_t size=20;
	if(key==-1){
		perror("error in ftok");
	}
	int shm_id=shmget(key,size,IPC_CREAT|0700);
	if(shm_id==-1){
		perror("error in getting shared memory");
	}
	char *shmpointer=shmat(shm_id,(void*)0,0);
	sprintf(shmpointer,"hii shared memory");
	printf("successfully writed in shared memory\n");
	printf("data from shared memory - %s\n",shmpointer);
	char *readpointer=shmat(shm_id,(void*)0,SHM_RDONLY);
	sprintf(readpointer,"hii shared memory");
	shmdt(shmpointer);
	shmdt(readpointer);
	printf("successfully detached pointer to shared memory\n");
	shmctl(shm_id,IPC_RMID,NULL);
	printf("successfully deleted shared memory\n");
	return 0;
}

/*
========================================================================================================
Output:

./a.out
successfully writed in shared memory
data from shared memory - hii shared memory
successfully detached pointer to shared memory
successfully deleted shared memory

========================================================================================================
*/
