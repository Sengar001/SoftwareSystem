/*
=======================================================================
Name: 7.c
Author: Abhishek Singh Sengar
Description: Write a program to copy file1 into file2 ($cp file1 file2).
Date: 22 Aug 2024
=======================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	int f1=open(argv[1],O_RDWR,0777);
	int f2=open(argv[2],O_RDWR,0777);
	char arr1[15]="file1 exist ";
	char arr2[15]="file2 exist ";
	char arr3[30];
	int a=write(f1,arr1,sizeof(arr1));
	write(f2,arr2,sizeof(arr2));
	lseek(f1,0,SEEK_SET);
	read(f1,arr3,a);
	write(f2,arr3,sizeof(arr3));
	//write(1,f2,sizeof(f1));
	return 0;
}

/*
================================================
Output: ./a.out f1.txt f2.txt
	cat f1.txt
	file1 exist
	cat f2.txt
	file2 exist file1 exist
================================================
*/

