#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	char arr[15];
	read(0,arr,10);
	write(1,arr,10);
	return 0;
}
