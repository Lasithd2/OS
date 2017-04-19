#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int main(){
    pid_t child1,child2;
    child1=fork();
    if(child1==0){
    	printf("Child 1 \n");
			
        }
        else{
        	child2=fork();
                if(child2==0){
                	printf("child 2 \n");
                }

                else{
                	printf("Parent \n");
                    }
        }
}

    
    
