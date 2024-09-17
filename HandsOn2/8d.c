#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalcaught(int sig){
        printf("SIGALRM caught\n");
        exit(1);
}
int main(){
        signal(SIGALRM,signalcaught);
        alarm(5);
	pause();
        return 0;
}

