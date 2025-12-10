#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "execute.h"

int execute_command(char** argv){
    if (argv[0] == NULL){
        return 1;
    }
    if (strcmp(argv[0], "exit") == 0 || strcmp(argv[0], "quit") == 0){
        return 0;
    }

    if (strcmp(argv[0], "cd") == 0){
        const char *path = (argv[1] ? argv[1] : getenv("HOME"));

        if (chdir(path) != 0){
            perror("cd");
        }
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0){
        perror("fork");
        return 1;
    }
    if (pid == 0){
        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    }

    int status;
    waitpid(pid, &status, 0);

    return 1;
}