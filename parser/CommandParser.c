#include "CommandParser.h"

#include "Utils.h"
#include "../utils/Constants.h"
#include "../variables/Variables.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* parsedCommand;

void parse(char* command) {

    // 1. Trim
    char trimmedCommand[MAX_LENGTH + 1];
    strcpy(trimmedCommand, trimCommand(command));

    // 2. Substitute
    parsedCommand = malloc(MAX_LENGTH + 1);
    parsedCommand = substituteVariables(trimmedCommand);
}

char* getCommand() {
    return parsedCommand;
}

void getCommandArguments(char* arguments[]) {
    char* tempCommand = malloc(MAX_LENGTH + 1);
    strcpy(tempCommand, parsedCommand);
    splitCommand(tempCommand, " ", arguments);
}

int getGroundState() {
    return getGroundStateVariable();
}
