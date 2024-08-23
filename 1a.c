#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	int count=symlink(argv[1],argv[2]);
	if(count==0){
		printf("successful");
	}else{
		printf("unsuccessful");
	}
	return 0;
}
