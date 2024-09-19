#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<stdlib.h>
int main(){
	key_t key=ftok("./21-header.h",1);
	if(key==-1){
		perror("ftok error");
	}
	int msg=msgget(key,IPC_CREAT|0777);
	if(msg==-1){
		perror("msgget error");
	}
	printf("key %d\n",key);
	printf("message queue id %d\n",msg);
	struct msqid_ds msg_info;
	int check=msgctl(msg,IPC_STAT,&msg_info);
	if(check==-1){
		perror("error in msg queue info");
	}
	printf("access permission %od\n",msg_info.msg_perm.mode);
    	printf("uid %d\n",msg_info.msg_perm.uid);
    	printf("gid %d\n",msg_info.msg_perm.gid);
    	printf("time of last message sent and received %ld\n",msg_info.msg_stime);
    	printf("time of last change in the message queue %ld\n",msg_info.msg_rtime);
    	printf("size of queue: %ld\n",msg_info.__msg_cbytes);
    	printf("number of messages in the queue %ld\n",msg_info.msg_qnum);
    	printf("maximum number of bytes allowed %ld\n",msg_info.msg_qbytes);
    	printf("pid of the msgsnd %d\n",msg_info.msg_lspid);
    	printf("pid of the msgrcv %d\n",msg_info.msg_lrpid);
	return 0;
}
