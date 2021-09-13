#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void printStat(int pid, int stat) {
    printf("Process status - %d\n", stat);
    if (WIFEXITED(stat)) {
        printf("Process %d terminated normally with %d\n", pid, WEXITSTATUS(stat));
    }
    if (WIFSIGNALED(stat)) {
        printf("Process %d terminated due to signal %d\n", pid, WTERMSIG(stat));
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("usage: ./prog [cmd] [arg]\n");
        return 1;
    }

    int pid;
    pid = fork();

    if (pid == -1) {
        perror("Fork failure");
        return 1;
    }

    //child
    if (pid == 0) {
        execvp(argv[1], argv + 1);
        perror("Execute argv error");
        return 1;
    }
    //parent
    int childStat;
    while (wait(&childStat) == -1) {
        if (errno == EINTR) {
            errno = 0;
            continue;
        }
        perror("Wait failure");
        return 1;
    }
    printStat(pid, childStat);
    return 0;
}
