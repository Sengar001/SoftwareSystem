#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
	if(argc<2){
		printf("invalid arguments");
	}
	int fd=open(argv[1],O_CREAT|O_RDWR,0777);
	char arr[25]="text before duplicacy\n";
	write(fd,arr,22);
	int dp=dup(fd);
	if(dp==-1){
		printf("error");
	}
	char brr[25]="text after duplicacy";
	write(dp,brr,25);
	close(fd);
	return 0;
}

