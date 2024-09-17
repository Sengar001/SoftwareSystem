#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void* work(void * argc){
	int id=*(int*)argc;
	printf("running thread is %d\n",id);
}
int main(){
	pthread_t th[3];
	int id[3];
	for(int i=0;i<3;i++){
		id[i]=i;
		int ph=pthread_create(&th[i],NULL,work,&id[i]);
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
