#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

int main(){
    int pipefd[2];
    pid_t child;
    char message[20];
    
    pipe(pipefd);
    child=fork();
    if(child==0){
                 close(pipefd[1]);
                 read(pipefd[0],message,18);
                 }
    else{
         close(pipefd[0]);
         write(pipefd[1],"Hello from parent",18);
        
         }
         }             
