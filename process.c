#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "process.h"

void create_process() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child Process Created\n");
        printf("Child PID: %d\n", getpid());
    } else {
        wait(NULL);
        printf("Parent Process Resumed\n");
    }
}
