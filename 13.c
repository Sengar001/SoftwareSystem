
/*
==============================================================================================================
Name: 13.c
Author: Abhishek Singh Sengar
Description: Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 23 Aug 2024
==============================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>
int main(){
	int val;
	fd_set rfds;
	struct timeval time;
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);
	time.tv_sec=10;
	time.tv_usec=0;
	val=select(1,&rfds,NULL,NULL,&time);
	if(val==-1){
		printf("error");
	}else if(val){
		printf("data is available");
	}else{
		printf("timeout");
	}
	return 0;
}

/*
================================================
Output: ./a.out
	abhishek
	data is available
================================================
*/

