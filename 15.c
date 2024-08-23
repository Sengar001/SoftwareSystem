#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	extern char **environ;
	while(*environ){
		printf("%s\n",*environ);
		*environ++;
	}
	return 0;
}
