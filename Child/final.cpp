#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t child;
    int pipefd[2];
    int ret;
    char buf[20];
    ret =pipe(pipefd);
    
           child=fork();
          if(child==0){
                            
                              close(pipefd[1]);
                              read(pipefd[0],buf,18);
                              printf("Message from paren %s\n",buf);
                              }
                              
                              else{
                                     
                              close(pipefd[0]);
                                   write(pipefd[1],"Hello from parent",18);
                                  
                                   }
                                
                                   }
