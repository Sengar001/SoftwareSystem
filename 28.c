#include<stdio.h>
#include<sched.h>
int main(){
	printf("minimum real time priority for FIFO %d\n",sched_get_priority_min(SCHED_FIFO));
	printf("maximum real time priority for FIFO %d\n",sched_get_priority_max(SCHED_FIFO));
	printf("minimum real time priority for RR %d\n",sched_get_priority_min(SCHED_RR));
	printf("maximum real time priority for RR %d\n",sched_get_priority_max(SCHED_RR));
	printf("minimum real time priority for other %d\n",sched_get_priority_min(SCHED_OTHER));
	printf("maximum real time priority for other %d\n",sched_get_priority_min(SCHED_OTHER));
	return 0;
}
