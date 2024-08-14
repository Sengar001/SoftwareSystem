#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char** argv){
	int f1=open(argv[1],O_CREAT|O_RDWR,0777);
	int f2=open(argv[2],O_CREAT|O_RDWR,0777);
	char arr1[15]="file1 exist ";
	char arr2[15]="file2 exist ";
	write(f1,arr1,12);
	write(f2,arr2,12);
	char arr3[15];
	lseek(f1,0,SEEK_SET);
	read(f1,arr3,12);
	write(f2,arr3,12);
	char arr4[25];
	lseek(f2,0,SEEK_SET);
	read(f2,arr4,24);
	write(1,arr4,24);
	return 0;
}
