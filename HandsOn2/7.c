/*
========================================================================================================
Name : 7
Author : Abhishek Singh Sengar
Description : Write a simple program to print the created thread ids.
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void* work(void * argc){
        long long int id=pthread_self();
        printf("running thread id is %llu\n",id);
}

int main(){
        pthread_t th[3];
        for(int i=0;i<3;i++){
                int ph=pthread_create(&th[i],NULL,work,NULL);
                if(ph!=0){
                        perror("error in thread create\n");
                        exit(1);
                }
        }
        for(int i=0;i<3;i++){
                int j=pthread_join(th[i],NULL);
                if(j!=0){
                        perror("error in join\n");
                        exit(1);
                }
        }
        printf("all thread completed\n");
        return 0;
} 

/*
========================================================================================================
Output:

./a.out
running thread id is 139987584546496
running thread id is 139987576153792
running thread id is 139987567761088
all thread completed


========================================================================================================
*/
