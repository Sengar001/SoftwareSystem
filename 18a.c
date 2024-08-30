#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments");
		return -1;
	}
	struct ticket{
		int window;
		int ticket;
	};
	struct ticket t1={1,2};
	struct ticket t2={2,3};
	struct ticket t3={3,4};
	struct ticket buffer[3];
	buffer[0]=t1;
	buffer[1]=t2;
	buffer[2]=t3;
	int fd=open(argv[1],O_WRONLY);
	write(fd,&buffer,sizeof(buffer));
	return 0;
}
