#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdbool.h>
int main(){
	bool turn=true;
	while(true){
		if(turn){
			int f1=creat("f1",0755);
			int f2=creat("f2",0755);
			int f3=creat("f3",0755);
			int f4=creat("f4",0755);
			int f5=creat("f5",0755);
			turn=false;
		}
	}
	return 0;
} 

