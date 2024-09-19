#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include "./21-header.h"
int main(){
        char send[50]="sending data from 21b to 21a";
        char recv[50];
        init();
        int fd1=open(file1,O_RDONLY);
        if(fd1==-1){
                perror("error in opening file");
        }       
        int fd2=open(file2,O_WRONLY);
        if(fd2==-1){
                perror("error in opening file");
        }       
        write(fd2,&send,sizeof(send));
        read(fd1,&recv,50);
        write(1,&recv,sizeof(recv));
        close(fd1);
        close(fd2);
        return 0;
}  
