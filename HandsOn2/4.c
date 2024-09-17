#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A"(dst));
}

int main(){
	unsigned long long int start,end;
	start=rdtsc();
	for(int i=0;i<100;i++){
	getpid();
	}
	end=rdtsc();
	printf("time taken to execute getpid %lld\n",end-start);
}	
