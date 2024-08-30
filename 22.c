#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments\n");
	}
	int fd=open(argv[1],O_RDWR);
	int p=fork();
	char parent[15]="I am Parent";
	char child[15]="I am Child";
	if(p){
		write(fd,parent,sizeof(parent));
	}else{
		write(fd,child,sizeof(child));
	}
	return 0;
}
