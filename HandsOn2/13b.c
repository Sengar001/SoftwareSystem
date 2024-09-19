#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
	int pid=atoi(argv[1]);
	int kill1=kill(pid,SIGSTOP);
        if(kill1==0){
		printf("error in sending signal\n");
	}
       	return 0;
}
