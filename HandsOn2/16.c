#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
        int parentfd[2],childfd[2];
        char child_buffer[30],chbuffer[30],parent_buffer[30],pabuffer[30];
        int p=pipe(parentfd);
        if(p==-1){
                printf("error in creating parent pipe\n");
        }
	int q=pipe(childfd);
        if(q==-1){
                printf("error in creating child pipe\n");
        }
	 int f=fork();
        if(f==0){
		close(parentfd[1]);
		close(childfd[0]);
                char child_buffer[30]="Hii parent I am your child";
		char chbuffer[30];
		int child_write=write(childfd[1],&child_buffer,sizeof(child_buffer));
		if(child_write==-1){
			printf("error on writing from child\n");
		}
		int child_read=read(parentfd[0],&chbuffer,sizeof(parent_buffer));
                if(child_read==-1){
                        printf("error on reading to child\n");
                }
                write(1,&chbuffer,sizeof(chbuffer));
        }else{
		close(parentfd[0]);
		close(childfd[1]);
		char parent_buffer[30]="Hii child I am parent!";
		char pabuffer[30];
                int parent_write=write(parentfd[1],&parent_buffer,sizeof(parent_buffer));
                if(parent_write==-1){
                        printf("error on writing from parent\n");
                }
		int parent_read=read(childfd[0],&pabuffer,sizeof(child_buffer));
                if(parent_read==-1){
                        printf("error on reading to parent\n");
                }
                write(1,&pabuffer,sizeof(pabuffer));

        }
}

