/*
========================================================================================================
Name : 34.b
Author : Abhishek Singh Sengar
Description : Write a program to create a concurrent server using pthread_create.
Date: 12 Sept, 2024.
========================================================================================================
*/


#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void communicate(int *fd2) {
    char data[50];
    write(*fd2,"I AM SERVER",11);
    read(*fd2,data,sizeof(data));
    printf("received from client: %s\n",data);
    close(*fd2);
}
int main(){
    struct sockaddr_in address,client;
    char data[50];
    pthread_t thread_id;
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
    printf("binding to socket is successful\n");
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
		if(pthread_create(&thread_id,NULL,(void *)communicate,&fd2))
                	perror("error while creating thread");
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
