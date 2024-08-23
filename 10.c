#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd=open("seek.txt",O_CREAT|O_RDWR,0777);
	char arr[10];
	read(0,arr,10);
	write(fd,arr,sizeof(arr));
	int l=lseek(fd,10,SEEK_CUR);
	getchar();
	write(fd,arr,sizeof(arr));
	printf("lseek value = %d",l);
	return 0;
}


