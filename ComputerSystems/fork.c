/*
 Example of fork()
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t Fork(void);

int main(int argc, char ** argv)
{
    int x = 1;
    int pid;

    if ((pid = fork()) == 0)
    {
        printf("child: x = %d\n", ++x);
        exit(0);
    }
    printf("parent: x = %d\n", --x);

}

pid_t Fork(void)
{
    pid_t pid;
    
    if ((pid = fork()) < 0)
        printf("Fork error\n");
    return pid;
}


