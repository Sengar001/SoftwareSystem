#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
int main(){
        struct rlimit r;
        int f=getrlimit(RLIMIT_CPU,&r);
        if(f==-1){
                perror("error in getrlimit\n");
        }
        printf("limit befor update\n");
        printf("soft limit: %ld\n",r.rlim_cur);
        printf("hard limit: %ld\n",r.rlim_max);
	r.rlim_cur=200;
	int s=setrlimit(RLIMIT_CPU,&r);
	if(s==-1){
		perror("error in setrlimit\n");
	}
	printf("limit after update\n");
        printf("soft limit: %ld\n",r.rlim_cur);
        printf("hard limit: %ld\n",r.rlim_max);
	return 0;

}

