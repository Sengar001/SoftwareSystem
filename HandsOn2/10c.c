#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void caught(){
    printf("SIGFPE caught\n");
    exit(1);
}
int main(){
        struct sigaction s;
        s.sa_handler=caught;
        s.sa_flags=0;
        int p=sigaction(SIGFPE,&s,NULL);
        if(p==-1){
                 perror("Error");
        }
        int a=1/0;
        return 0;
} 
