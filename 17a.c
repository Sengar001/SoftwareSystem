#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	if(argc!=2){
	printf("invalid arguments");
	}
	int fd=open(argv[1],O_WRONLY);
	int ticketno[1]={0};
	int w=write(fd,ticketno,1);
	return 0;
}
