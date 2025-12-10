#include "builtin.h"

int builtin(char** argv){
    if (strcmp(argv[0], "pwd") == 0){
        printf("current dir");
        // add code for implementing pwd
        return 1;
    }
    else if (strcmp(argv[0], "cd") == 0){
        printf("change to folder");
        // add code for implementing cd ?? might not have to is should be in execute...
        return 1;
    }
    else if (strcmp(argv[0], "exit") == 0){
        printf("exit");
        // add code for exit also might not have to should be in the main loop
        return 1;
    }
    else if (strcmp(argv[0], "quit") == 0){
        printf("exit");
        // add code for quit same deal as exit if the main works correctly this might not be needed
        return 1;
    }
}
