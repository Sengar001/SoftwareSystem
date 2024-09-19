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
	struct msqid_ds msg_info;
	int check=msgctl(msg,IPC_STAT,&msg_info);
	if(check==-1){
		perror("error in getting message info");
	}
	printf("current mode %o\n",msg_info.msg_perm.mode);
	msg_info.msg_perm.mode=0777;
	check=msgctl(msg,IPC_SET,&msg_info);
	check=msgctl(msg,IPC_STAT,&msg_info);
        if(check==-1){
                perror("error in changing permission");
        }else{
		printf("message queue permission changes succesfuly!\n");
	}
	printf("current mode %o\n",msg_info.msg_perm.mode);
	return 0;
}

