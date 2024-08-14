#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd=open("duplicate1.txt",O_CREAT|O_RDWR,0777);
	char arr[20]="before duplicacy\n";
	write(fd,arr,20);
	int dp=dup2(fd,9);
	char brr[20]="after duplicacy";
	write(dp,brr,20);
	close(fd);
	return 0;
}
