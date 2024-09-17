#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalcaught(int sig){
        printf("SIGFPE caught\n");
        exit(1);
}
int main(){
        signal(SIGFPE,signalcaught);
	int result=1/0;
        return 0;
}
    
