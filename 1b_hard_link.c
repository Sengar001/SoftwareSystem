#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int count=link("File1","hardlink");
	if(count==0){
		printf("successful");
	}
	else{
		printf("unsuccessful");
	}
	return 0;
}

