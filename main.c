#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int global_var = 10;

int main() {
    int local_var = 20;
    printf("[2] address of global variable: %p,\tcontent of global variable %d\n", &global_var, global_var);
    printf("[2] address of local variable: %p,\tcontent of local variable: %d\n", &local_var, local_var);
    printf("[3] pid: %d\n", getpid());
    int pid = fork();
    if (pid == 0) {
        printf("[4] child pid from child: %d\n", getpid());
        printf("[5] parent pid from child: %d\n", getppid());
        printf("[6] address of global variable: %p,\tcontent of global variable %d\n", &global_var, global_var);
        printf("[6] address of local variable: %p,\tcontent of local variable: %d\n", &local_var, local_var);
        global_var = 30;
        local_var = 40;
        printf("[7] new content of global variable: %d\n", global_var);
        printf("[7] new content of local variable: %d\n", local_var);
        exit(5);
    }
    else {
        printf("[8] address of global variable: %p,\tcontent of global variable %d\n", &global_var, global_var);
        printf("[8] address of local variable: %p,\tcontent of local variable: %d\n", &local_var, local_var);
        sleep(30);
        int status;
        int child_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("[11] child process exited with code %d\n", WEXITSTATUS(status));
        }
        else {
            printf("[11] child process did not exit normally\n");
        }
    }
    return 0;
}