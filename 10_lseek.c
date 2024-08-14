#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd=open("seek.txt",O_CREAT|O_RDWR,0777);
	char arr[10];
	read(0,arr,10);
	write(fd,arr,10);
	int l=lseek(fd,10,SEEK_CUR);
	getchar();
	read(0,arr,10);
	printf("lseek value = %d",l);
	write(fd,arr,10);
	return 0;
}


