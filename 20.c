#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
int main(){
	int pri=getpriority(PRIO_PROCESS,0);
	printf("current priority %d\n",pri);
	int newpri=15;
	pri=nice(newpri);
	printf("new priority %d\n",pri);
	return 0;
}
