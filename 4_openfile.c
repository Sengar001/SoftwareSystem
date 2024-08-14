#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int count=open("File1",O_CREAT|O_EXCL,O_RDWR);
	if(count!=-1){
		printf("File Open Successful");
	}else{
		printf("Unsuccessful");
	}
	return 0;
}


