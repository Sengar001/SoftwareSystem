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
        signal(SIGPROF,signalhandler);
        struct itimerval time;
        time.it_interval.tv_sec=0;
        time.it_interval.tv_usec=0;
        time.it_value.tv_sec=10;
        time.it_value.tv_usec=10;
        int f=setitimer(ITIMER_PROF,&time,NULL);
        if(f==-1){
                perror("error in setitimer\n");
        }
        while(1){
	}
}

