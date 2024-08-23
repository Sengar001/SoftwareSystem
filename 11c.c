#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	if(argc<2){
		printf("invalid arguments");
	}
	int fd=open(argv[1],O_CREAT|O_RDWR,0777);
	char arr[20]="before copy\n";
	write(fd,arr,12);
	int dp=fcntl(fd,F_DUPFD);
	if(dp==-1){
		printf("error");
	}
	char brr[20]="after copy";
	write(dp,brr,20);
	return 0;
}



