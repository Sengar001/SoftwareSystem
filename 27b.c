#include<stdio.h>
#include<unistd.h>
int main(){
	execlp("/bin/ls","ls",NULL);
	return 0;
}
