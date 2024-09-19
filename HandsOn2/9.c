#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void stop(int sig){
	printf("SIGINT is caught\n");
	exit(1);
}

int main(){
	__sighandler_t status;
	status=signal(SIGINT,SIG_IGN);
	if(status==SIG_ERR){
		perror("error while ignoring signal\n");
	}
	sleep(5);
	status=signal(SIGINT,SIG_DFL);
	if(status==SIG_ERR){
		perror("error while signal\n");
	}
        status=signal(SIGINT,stop);
        if(status==SIG_ERR){
                perror("error while signal\n");
        }
	while(1){
	}

	return 0;
}
