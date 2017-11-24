#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#include "parser/CommandParser.h"
#include "parser/Utils.h"
#include "files/FileProcessing.h"
#include "files/FileSetup.h"
#include "executor/CommandExecutor.h"
#include "utils/Constants.h"

typedef enum {false = 0, true = 1} bool;
FILE* fptr;

void startLoop(bool inputFromFile);

int main(int argc, char* argv[]) {

    setupFiles();

    if(argc > 1) {
        // BATCH MODE
        fptr = openFile(argv[1]);
        if(fptr == NULL) {
            printf(RED "ERROR: FILE OPENING\n" RESET);
            return 0;
        }
        startLoop(true);
    } else {
        // INTERACTIVE MODE
        startLoop(false);
    }

    return 0;
}

void startLoop(bool inputFromFile) {

    chdir("/");

    char command[MAX_LENGTH + 1];
    char parsedCommand[MAX_LENGTH + 1];
    char* arguments[MAX_LENGTH + 1];

    while(1) {

        if(inputFromFile == 1) {
            // Read the input from the file
            printf("\n");
            if(!fgets(command, MAX_LENGTH + 2, fptr)) {
                return;
            }
            printf("Command: %s\n", command);
        } else {
            printf("Shell> ");
            // Read the input from the console
            if(!fgets(command, MAX_LENGTH + 2, stdin)){
                return;
            }
        }

        // 0. Check the length of the command..
        if(isValidLength(command) == 0) {
            continue;
        }

        if(isComment(command) == 1) {
            continue;
        }

        // 1. Parsing of Data
        parse(command);
        strcpy(parsedCommand, getCommand());
        getCommandArguments(arguments);


        // 2. Execution of Data
        execute(parsedCommand,arguments);
    }
}
