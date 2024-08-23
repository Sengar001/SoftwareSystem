#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	char arr[15];
	int int_put=read(0,arr,10);
	printf("%d",int_put);
	write(1,arr,sizeof(arr));
	return 0;
}
