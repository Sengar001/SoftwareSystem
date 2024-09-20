/*
========================================================================================================
Name : 34.a
Author : Abhishek Singh Sengar
Description : Write a program to create a concurrent server using fork.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
int main(){
    struct sockaddr_in address,client;
    char data[50];
    int fd1=socket(AF_INET,SOCK_STREAM,0);
    if(fd1==-1){
        perror("error while creating socket");
    }
    address.sin_addr.s_addr=htonl(INADDR_ANY);
    address.sin_family=AF_INET;
    address.sin_port=htons(8080);
    int status1=bind(fd1,(struct sockaddr *)&address,sizeof(address));
    if(status1==-1){
        perror("error while binding name to socket");
    }
    printf("Binding to socket was successful!\n");
    int status2=listen(fd1,2);
    if(status2==-1){
        perror("error while trying to listen for connections");
    }
    printf("now listening for connections on a socket\n");
    while (1){
        int client_size=(int)sizeof(client);
        int fd2=accept(fd1,(struct sockaddr *)&client,&client_size);
        if(fd2==-1){
            perror("error while accepting a connection");
	}else{
            if(fork()==0){
                write(fd2,"I AM SERVER",11);
                printf("data sent to client\n");
		read(fd2,data,sizeof(data));
                printf("data from client: %s\n",data);
            }//else{
               // close(fd2);
            //}
	    close(fd2);
        }
    }
    close(fd1);
    return 0;
}

/*
========================================================================================================
Output:

./a.out
binding to socket is successful
now listening for connections on a socket
received from client: I AM CLIENT



========================================================================================================
*/
