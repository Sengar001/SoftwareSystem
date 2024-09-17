#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void caught(){
    printf("SIGINT caught\n");
    exit(1);
}
int main(){
        struct sigaction s;
        s.sa_handler=caught;
        s.sa_flags=0;
        int p=sigaction(SIGINT,&s,NULL);
        if(p==-1){
                 perror("Error");
        }
        while(1){
	}
        return 0;
}
