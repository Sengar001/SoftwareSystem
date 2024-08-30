/*
=============================================================================================================
Name: 10.c
Author: Abhishek Singh Sengar
Description:  Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
		a. check the return value of lseek
		b. open the file with od and check the empty spaces in between the data.
Date: 22 Aug 2024
=============================================================================================================
*/


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

/*
================================================
Output: ./a.out
	abhishek1

	lseek value = 20
================================================
*/


