#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int count=symlink("File","soflink");
	if(count==0){
		printf("successful");
	}else{
		printf("unsuccessful");
	}
	return 0;
}
