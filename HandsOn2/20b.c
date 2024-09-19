#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
        char *fifofile="./20-fifo3";     
        char buff[50];
        int fd=open(fifofile,O_RDONLY);
        if(fd==-1){
                perror("error in opening in file\n");
        }       
        read(fd,&buff,50);
	write(1,&buff,sizeof(buff));
        close(fd);
        return 0;
}   
