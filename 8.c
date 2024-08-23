#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int count=open("line.txt",O_RDONLY);
	char arr[50];
	int ptr=0;
	while(1){
		int byte=read(count,&arr[ptr],1);
		if(byte==0){
			break;
		}
		if(arr[ptr]=='\n'){
			write(1,arr,ptr);
			getchar();
			ptr=0;
			continue;
		}
		ptr++;
	}
	close(count);
	return 0;
}
