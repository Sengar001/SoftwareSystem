/*
========================================================================================================
Name : 33
Author : Abhishek Singh Sengar
Description : Write a program to communicate between two machines using socket.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/ip.h>
int main(){
	char data[50];
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1){
		perror("error in creating socket");
	}
	struct sockaddr_in address;
	address.sin_addr.s_addr=htonl(INADDR_ANY);
    	address.sin_family=AF_INET;
    	address.sin_port=htons(8080);
	int status=connect(fd,(struct sockaddr*)&address,sizeof(address));
	if(status==-1){
		perror("error in connecting to server");
	}
	printf("client server connection successfully\n");
	int readdata=read(fd,data,sizeof(data));
	if(readdata==-1){
		perror("error in reading data");
	}
	printf("data from server: %s\n",data);
	int writedata=write(fd,"I AM CLIENT",11);
        if(writedata==-1){
                perror("error in reading data");
        }
	printf("data sent to server\n");
	close(fd);
	return 0;
}

/*
========================================================================================================
Output:

./a.out
client server connection successfully
data from server: I AM SERVER
data sent to server


========================================================================================================
*/
