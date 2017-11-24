#include "Utils.h"

#include "../utils/Constants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int groundState;

int isValidLength(char* command) {

    if((strlen(command) == 1 && command[0] == '\n') || getLastCharIndex(command) == -1) {
        printf(RED "ERROR: Command is too small\n" RESET);
        return 0;
    }
    else if(strlen(command) == MAX_LENGTH + 1 && command[MAX_LENGTH] != '\n') {
        printf(RED "ERROR: Command is too long\n" RESET);
        // Clear STDIN
        char c = getchar();
        while (c != '\n' && c != EOF) {
            c = getchar();
        }
        return 0;
    }
    return 1;
}

int isComment(char* command) {

    int i;
    for(i = 0; i < strlen(command); i++) {
        if(!isspace(command[i])) {
            if(command[i] == COMMENT_IDENTIFIER) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return -1;
}

char* trimCommand(char* command) {

    int i,length = strlen(command), trimFactor = length - 1;
    char* trimmedCommand = malloc(MAX_LENGTH);

    // Setting the ground state to foreground
    setGroundStateVariable(0);

    if(command[getLastCharIndex(command)] == BACKGROUD_INDENTIFIER) {
        trimFactor = getLastCharIndex(command) - 1;
        // Setting the ground state to background
        setGroundStateVariable(1);
    }

    for(i = 0; i < trimFactor; i++) {
        trimmedCommand[i] = command[i];
    }

    trimmedCommand[i] = STRING_TERMINATOR;

    return trimmedCommand;
}

int getLastCharIndex(char* command) {

    int i;
    int index = -1, length = strlen(command) - 1;

    for(i = 0; i < length; i++) {
        if(!isspace(command[i])) {
            index = i;
        }
    }

    return index;
}

void splitCommand(char* command, char* delimiter, char* arguments[]) {

    int count = 0;
    char* token = strtok(command, delimiter);

    while(token != NULL) {
        arguments[count++] = token;
        token = strtok(NULL, delimiter);
    }

    arguments[count++] = NULL;
}

int countArguments(char* command, char* delimiter) {

    int count = 0;
    char* token = strtok(command, delimiter);

    while(token) {
        count++;
        token = strtok(NULL, delimiter);
    }

    return count;
}

void setGroundStateVariable(int state) {
    groundState = state;
}

int getGroundStateVariable() {
    return groundState;
}
