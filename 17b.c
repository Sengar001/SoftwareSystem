#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments");
		return -1;
	}
	int fd=open(argv[1],O_RDWR);
	int ticket;
	read(fd,&ticket,1);
	printf("ticket sold = %d\n",ticket);
	struct flock fc;
	fc.l_type=F_WRLCK;
	fc.l_whence=SEEK_SET;
	fc.l_start=0;
	fc.l_len=0;
	int p=fcntl(fd,F_SETLKW,&fc);
	if(p==-1){
		printf("error");
	}
	lseek(fd,0,SEEK_SET);
	read(fd,&ticket,1);
	ticket++;
	lseek(fd,0,SEEK_SET);
	write(fd,&ticket,1);
	printf("press enter for ticket booking\n");
	getchar();
	fc.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&fc);
	printf("your ticket no. = %d\n",ticket);
	return 0;

}
