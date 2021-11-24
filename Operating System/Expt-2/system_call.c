#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    printf("Inside Main\n");
    int res = 1;
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Error Genrated\n");
    }
    if (pid == 0)
    {
        printf("Inside Child Process!! , PID=%d", getpid());
        execl("./a.out", "code", argv[1], argv[2], NULL);
    }
    else
    {
        printf("Inside Parent Process Id=%d\n", getpid());
        wait(&res);
        if (WIFEXITED(res) == 1)
        {
            printf("Terminating Normally\n");
        }
        else
        {
            printf("Terminating Ab-Normally\n");
            exit(0);
        }
    }
}