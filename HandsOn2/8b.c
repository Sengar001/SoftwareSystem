#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalcaught(int sig){
        printf("SIGSEGV caught\n");
        exit(1);
}
int main(){
        signal(SIGINT,signalcaught);
        while(1){
	}
        return 0;
}

