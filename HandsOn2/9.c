#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void stop(int sig){
}

int main(){
	__sighandler_t status;
	status=signal(SIGINT,stop);
	if(status==SIG_ERR){
		perror("error while signal\n");
	}
	sleep(10);
	status=signal(SIGINT,SIG_DFL);
	if(status==SIG_ERR){
		perror("error while signal\n");
	}
	sleep(10);
	return 0;
}
