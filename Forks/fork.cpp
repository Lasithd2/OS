#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
# include<conio.h>
int main()
{
    printf("I m %d\n",(int) getpid());
    
    pid_t pid = createProcessEx();
    printf("Fork returned: %d\n", (int) pid);
    printf("I am %d\n, (int) getpid()); 
   getch();
}
