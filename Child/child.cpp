#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char *arg[]){
    pid_t child;
    int pipefd[2];
    int ret;
    char message[20];
    ret =pipe(pipefd);
    
           
          if((child=fork())==0){
                              printf("The child process \n");
                              close(pipefd[0]);
                                   write(pipefd[1],"Hello from parent",18);
                             
                              }
                              
                              else{
                                   close(pipefd[1]);
                              read(pipefd[0],message,18);
                              printf("Message from paren %s\n",message);
                                   }
                                   return 0;
                                   }
                                   
           
    
