#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	char *fifofile="./20-fifo3";
	int f=mkfifo(fifofile,0777);
	if(f==-1){
		perror("error in creating fifo file\n");
	}
	char buff[50]="sending data from 20.a";
	int fd=open(fifofile,O_WRONLY);
	if(fd==-1){
		perror("error in opening in file\n");
	}
	write(fd,&buff,sizeof(buff));
	close(fd);
	return 0;
}
