#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
void rlimit(int resource,char *name){
	struct rlimit r;
        int f=getrlimit(resource,&r);
	if(f==-1){
		perror("error in getrlimit\n");
	}
	printf("%s\n",name);
	printf("soft limit: %ld\n",r.rlim_cur);
	printf("hard limit: %ld\n",r.rlim_max);

}

int main(){
	rlimit(RLIMIT_CPU,"RLIMIT_CPU");
   	rlimit(RLIMIT_FSIZE,"RLIMIT_FSIZE");
    	rlimit(RLIMIT_DATA,"RLIMIT_DATA");
    	rlimit(RLIMIT_STACK,"RLIMIT_STACK");
    	rlimit(RLIMIT_CORE,"RLIMIT_CORE");
    	rlimit(RLIMIT_NOFILE,"RLIMIT_NOFILE");
   	rlimit(RLIMIT_AS,"RLIMIT_AS");
    	rlimit(RLIMIT_NPROC,"RLIMIT_NPROC");
    	rlimit(RLIMIT_MEMLOCK,"RLIMIT_MEMLOCK");
    	rlimit(RLIMIT_LOCKS,"RLIMIT_LOCKS,");
	return 0;
}

