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
