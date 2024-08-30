#include<stdio.h>
#include<unistd.h>
int main(){
	int c=fork();
	if(c){
		sleep(5);
	}else{
		printf("ppid before orphan %d\n",getppid());
		sleep(10);
		printf("ppid after ophan %d\n",getppid());
	}
	return 0;
}

