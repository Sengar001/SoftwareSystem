#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
void signalcaught(int sig){
        printf("SIGALRM caught\n");
        exit(1);
}
int main(){
        signal(SIGALRM,signalcaught);
        struct itimerval time;
	time.it_value.tv_sec = 5;  
    	time.it_value.tv_usec = 0; 
    	time.it_interval.tv_sec = 0; 
	time.it_interval.tv_usec = 0; 
	int p=setitimer(ITIMER_REAL,&time,NULL);
	if(p==-1){
		perror("error in setitimer\n");
	}
        pause();
        return 0;
}

