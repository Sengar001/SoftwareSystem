/*
==================================================================================
Name: 9.c
Author: Abhishek Singh Sengar
Description: Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change

Date: 23 Aug 2024
=================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>
int main(int argc,char *argv[]){
	struct stat inform;
	int fd=open(argv[1],O_RDONLY);
	if(fd==-1){
		printf("error");
	}
	fstat(fd,&inform);
	printf("inode = %ld\n",inform.st_ino);
	printf("hardlink = %ld\n",inform.st_nlink);
	printf("uid = %d\n",inform.st_uid);
	printf("gid = %d\n",inform.st_gid);
	printf("size = %ld\n",inform.st_size);
	printf("blocksize = %ld\n",inform.st_blksize);
	printf("blocks = %ld\n",inform.st_blocks);
	char arr[30];
	time_t atime=inform.st_atim.tv_sec;
	struct tm *atime_tm=localtime(&atime);
	strftime(arr,sizeof(arr),"%Y-%m-%d %H:%M:%S",atime_tm);
	printf("last access = %s\n",arr);
	
	time_t mtime=inform.st_mtim.tv_sec;
	struct tm *mtime_tm=localtime(&mtime);
	strftime(arr,sizeof(arr),"%Y-%m-%d %H:%M:%S",mtime_tm);
	printf("last modified = %s\n",arr);

	time_t ctime=inform.st_ctim.tv_sec;
	struct tm *ctime_tm=localtime(&ctime);
	strftime(arr,sizeof(arr),"%Y-%m-%d %H:%M:%S",ctime_tm);
	printf("last change = %s\n",arr);
	return 0;
}

/*
================================================
Output: ./a.out line.txt
	inode = 4201682
	hardlink = 1
	uid = 1000
	gid = 1000
	size = 80
	blocksize = 4096
	blocks = 8
	last access = 2024-08-30 14:14:29
	last modified = 2024-08-27 22:27:31
	last change = 2024-08-27 22:27:31

================================================
*/


