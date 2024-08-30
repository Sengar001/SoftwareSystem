#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	execvp("/bin/ls",argv);
	return 0;
}
