#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void stop(int sig){
}

int main(){
	struct sigaction s;
	s.sa_handler=stop;
	s.sa_flags=0;
        int p=sigaction(SIGINT,&s,NULL);
        if(p==-1){
                perror("error while sigaction\n");
        }
        sleep(10);
	s.sa_handler=SIG_DFL;
        int q=sigaction(SIGINT,&s,NULL);
        if(q==-1){
                perror("error while sigaction\n");
        }
        sleep(10);
        return 0;
}

