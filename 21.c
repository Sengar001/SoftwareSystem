#include<stdio.h>
#include<unistd.h>
int main(){
	int c=fork();
	if(c){
		printf("parent pid %d\n",getpid());
	}else{
		printf("child pid %d\n",getpid());
	}
	return 0;
}
