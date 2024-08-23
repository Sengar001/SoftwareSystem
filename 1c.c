#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(){
	int count=mknod("fifo1",0755,0);
	if(count==0){
		printf("successful");
	}else{
		printf("unsuccessful");
	}
	return 0;
}
