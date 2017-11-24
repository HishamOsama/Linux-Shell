#include "Utils.h"

#include "../utils/Constants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cd(char* path) {

    if(chdir(path) == 0) {
        printf(GRN "Successful Directory Change\n" RESET);
    } else {
        printf(RED "Unsuccessful Directory Change\n" RESET);
    }

}

void echo(char* command) {

    int i, length = strlen(command), space = 0;
    int startingIndex = strlen("echo") + 1;

    for(i = startingIndex; i < length; i++) {
        if(command[i] == '\"') {
            i++;
            while(i < length && command[i] != '\"') {
                printf("%c", command[i]);
                i++;
            }
        } else if(command[i] == ' ') {
            if(space == 0) {
                printf("%c", command[i]);
                space = 1;
            }
        } else {
            space = 0;
            printf("%c", command[i]);
        }
    }

    printf("\n");
}

void linuxCommand(char* program,char* arguments[]) {

    execv(program, arguments);

    char* path = getenv("PATH");
    char* token = strtok(path,":");

    while(token != NULL) {
        char* target = malloc(strlen(token) + strlen(program) + 2);
        strcpy(target,token);
        strcat(target, "/");
        strcat(target, program);
        execv(target, arguments);
        token = strtok(NULL,":");
    }

}
