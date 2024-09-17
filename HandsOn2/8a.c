#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalcaught(int sig){
	printf("SIGSEGV caught\n");
	exit(1);b. SIGINT
}
int main(){
	signal(SIGSEGV,signalcaught);
	int *ptr=NULL;
	*ptr=1;
	return 0;
}
