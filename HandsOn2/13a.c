#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void caught(int sig){
	printf("SIGSTOP caught signal\n");
}
int main(){
	printf("process ID: %d\n",getpid());
	signal(SIGSTOP,caught);
	sleep(20);
	return 0;
}
