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
	int send=msgsnd(msg,&data,sizeof(data),0);
	if(send==-1){
		perror("error in sendinf message");
	}
	return 0;
}

