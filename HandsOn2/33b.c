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
	int fd1=socket(AF_INET,SOCK_STREAM,0);
	if(fd1==-1){
		perror("error in creating socket");
	}
	struct sockaddr_in address,client;
	address.sin_addr.s_addr=htonl(INADDR_ANY);
    	address.sin_family=AF_INET;
    	address.sin_port=htons(8080);
	int status1=bind(fd1,(struct sockaddr *)&address,sizeof(address));
	if(status1==-1){
		perror("error in binding");
	}
	printf("binding to socket successful\n");
	int status2=listen(fd1,2);
	if(status2==-1){
		perror("error in listen for connenction");
	}
	printf("listening for connection on a socket\n");
	int client_size=(int)sizeof(client);
	int fd2=accept(fd1,(struct sockaddr *)&client,&client_size);
	if(fd2==-1){
		perror("error in accepting the connection");
	}
	int writedata=write(fd2,"I AM SERVER",11);
        if(writedata==-1){
                perror("error in reading data");
        }
	printf("data send to client\n");
	int readdata=read(fd2,data,sizeof(data));
        if(readdata==-1){
                perror("error in reading data");
        }
        printf("data from client: %s\n",data);
	close(fd1);
	close(fd2);
	return 0;
}

/*
========================================================================================================
Output:

./a.out
binding to socket successful
listening for connection on a socket
data send to client
data from client: I AM CLIENT

======================================================================================================
*/
