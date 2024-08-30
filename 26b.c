#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	if(argc!=2){
		printf("invalid arguments\n");
	}
	execl(argv[1],argv[2],NULL);
	return 0;
}
