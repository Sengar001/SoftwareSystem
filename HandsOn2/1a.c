#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void signalhandler(){
	printf("time expired\n");
	exit(0);
}

int main(){
	signal(SIGALRM,signalhandler);
	struct itimerval time;
	time.it_interval.tv_sec=0;
	time.it_interval.tv_usec=0;
	time.it_value.tv_sec=10;
	time.it_value.tv_usec=10;
	int f=setitimer(ITIMER_REAL,&time,NULL);
	if(f==-1){
		perror("error in setitimer\n");
	}
	while(1){
	}
	return 0;
}

