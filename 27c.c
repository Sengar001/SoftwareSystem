#include<stdio.h>
#include<unistd.h>
int main(int argc,char *env[]){
	execle("/bin/ls","ls",NULL,env);
	return 0;
}
