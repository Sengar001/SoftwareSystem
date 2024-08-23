#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	if(argc<2){
		printf("invalid arguments");
	}
	int fd=open(argv[1],O_CREAT|O_RDWR,0777);
	char arr[20]="before duplicacy\n";
	write(fd,arr,17);
	int dp=dup2(fd,9);
	if(dp==-1){
		printf("error");
	}
	char brr[20]="after duplicacy";
	write(dp,brr,20);
	close(fd);
	return 0;
}
