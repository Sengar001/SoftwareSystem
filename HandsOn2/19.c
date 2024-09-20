/*
========================================================================================================
Name : 19.a
Author : Abhishek Singh Sengar
Description : Create a FIFO file by 
		a.mknod command
		b.mkfifo command
		c.use strace command to find out,which command(mknod or mkfifo) is better.
		d.mknod system call
		e.mkfifo library function
Date: 12 Sept, 2024.
========================================================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
int main(){
	char *name1="fifo1";
	char *name2="fifo2";
	int f1=mknod(name1,0777,0);
	if(f1==0){
		printf("successful\n");
	}else{
		printf("unsuccessful\n");
	}
	int f2=mkfifo(name2,0777);
	if(f2==0){
                printf("successful\n");
        }else{
                printf("unsuccessful\n");
        }
	return 0;
}

/*
========================================================================================================
Output:

sudo ./a.out
successful
successful


========================================================================================================
*/
