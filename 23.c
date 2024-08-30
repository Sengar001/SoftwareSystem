#include<stdio.h>
#include<unistd.h>
int main(){
	int c=fork();
	if(c){
		sleep(100);
		printf("parent process pid=%d\n",getpid());
		printf("child pid=%d\n",c);
	}
	else{
		printf("child process pid=%d\n",getpid());
		printf("parent pid=%d\n",getppid());
	}
	return 0;
}
