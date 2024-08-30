#include<stdio.h>
#include<unistd.h>
#include<sched.h>
int main(){
	int pid=getpid();
	int sc=sched_getscheduler(pid);
	switch(sc){
		case SCHED_FIFO: printf("current scheduler is FIFO\n");
				 break;
		case SCHED_RR: printf("current scheduler is RR\n");
			       break;
		case SCHED_OTHER: printf("current scheduler is OTHER\n");
				  break;
	}
	printf("enter the policy wants to modify 1.SHED_FIFO 2.SHED_RR 3.SHED_OTHER\n");
	int i;
	scanf("%d",&i);
	struct sched_param par;
	switch(i){	
		case 1: par.sched_priority=99;
			sched_setscheduler(pid,SCHED_FIFO,&par);
			break;
		case 2: par.sched_priority=99;
			sched_setscheduler(pid,SCHED_RR,&par);
			break;
		case 3: par.sched_priority=0;
			sched_setscheduler(pid,SCHED_OTHER,&par);
			break;
		default: printf("invalid case\n");
			 break;
	 }
	int npid=getpid();
	sc=sched_getscheduler(npid);
	switch(sc){
                case SCHED_FIFO: printf("current scheduler is FIFO\n");
                                 break;
                case SCHED_RR: printf("current scheduler is RR\n");
                               break;
                case SCHED_OTHER: printf("current scheduler is OTHER\n");
                                  break;
        }

	return 0;
}
