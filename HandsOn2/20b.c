/*
========================================================================================================
Name : 20
Author : Abhishek Singh Sengar
Description : Write two programs so that both can communicate by FIFO - Use one way communication.
Date: 12 Sept, 2024.
========================================================================================================
*/

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

/*
========================================================================================================
Output:

./a
sending data from 20.a

========================================================================================================
*/
