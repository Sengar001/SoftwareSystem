#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
int main(){
	int child;
	child=fork();
	if(child==0){
		printf("%d child PID\n",getpid());
		printf("%d parent PID\n",getppid());
		sleep(5);
		int kill1=kill(getppid(),SIGKILL);
		if(kill1==0){
			printf("parent killed\n");
			sleep(5);
			printf("child exist\n");
		}else{
			printf("error in killing parent\n");
		}
	}else{
		while(1);
	}
	return 0;
}

