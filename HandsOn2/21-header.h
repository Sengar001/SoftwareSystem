#include<errno.h>
char *file1="./21-fifo1";
char *file2="./21-fifo2";
void init(){
	int f1=mkfifo(file1,0777);
	if(f1==-1){
		perror("error in creating fifo file\n");
	}
	int f2=mkfifo(file2,0777);
	if(f2==-1){
		perror("error in creating fifo file\n");
	}
}
