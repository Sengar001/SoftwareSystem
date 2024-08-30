#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
unsigned long long rdtsc(){
       unsigned long long int  p;
       __asm__ __volatile__("rdtsc":"=a" (p));
       return p;
}
int main(){
	long long int start,end;
	start=rdtsc();
	printf("pid: %d\n",getpid());
	end=rdtsc();
	printf("time taken %f\n",(end-start)/2.5);
	return 0;
}

