#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/file.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments");
		return -1;
	}
	struct flock fc;
	fc.l_type=F_WRLCK;
	int fd=open(argv[1],O_WRONLY);
	int p=fcntl(fd,F_SETLKW,&fc);
	if(p==-1){
		printf("error");
	}
	printf("lock acquried\n");
	printf("press enter to release lock\n");
	getchar();
	fc.l_type=F_UNLCK;
	p=fcntl(fd,F_SETLK,&fc);
	if(p==-1){
		printf("error");
	}
	return 0;
}


