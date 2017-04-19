#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int main(){
    int x=0;
    fork();
    x++;
    if(fork()){
               x++;
               printf("%d",x);
}

    
    
