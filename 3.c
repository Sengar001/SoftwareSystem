#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int count=creat("filedescriptor",0755);
	printf("%d\n",count);
	return 0;
}
