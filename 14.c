#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("invalid arguments");
	}
	struct stat st;
	int p=lstat(argv[1],&st);
	if(p==-1){
		printf("lstat error");
	}
	switch(st.st_mode & S_IFMT){
	   case S_IFBLK:  printf("block device");           
			  break;
           case S_IFCHR:  printf("character device");       
			  break;
           case S_IFDIR:  printf("directory");              
			  break;
           case S_IFIFO:  printf("FIFO");              
			  break;
           case S_IFLNK:  printf("symlink");                
			  break;
           case S_IFREG:  printf("regular file");           
			  break;
           case S_IFSOCK: printf("socket");                 
			  break;
           default:       printf("unknown");               
			  break;
	}
	return 0;
}
