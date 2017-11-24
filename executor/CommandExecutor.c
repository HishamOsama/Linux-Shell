#include "CommandExecutor.h"

#include "Utils.h"
#include "../utils/Constants.h"
#include "../variables/Variables.h"
#include "../files/FileProcessing.h"
#include "../files/FileSetup.h"
#include "../parser/CommandParser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <ctype.h>

void logState() {
    appendFile(getLogFilPath(), "Child process was terminated");
}

void execute(char* command, char* arguments[]) {

    appendFile(getHistoryFilePath(), command);

    // 0) Trim Export
    if(strcmp(arguments[0], "export") == 0 ) {
        command += strlen(arguments[0]) + 1;
    }

    // 1) Try setting the command as a variable
    if(setVariable(command) == 1) {
        return;
    }

    // 2) Factory trying to execute the command
    if(strcmp(arguments[0], "cd") == 0) {
        cd(arguments[1]);
    } else if(strcmp(arguments[0], "echo") == 0) {
        echo(command);
    } else if(strcmp(arguments[0], "exit") == 0) {
        exit(0);
    } else if(strcmp(arguments[0], "history") == 0) {
        printFile(getHistoryFilePath());
    } else {

        int groundState = getGroundState();

        signal(SIGCHLD, logState);
        siginfo_t childstat;
        pid_t pid;
        pid = fork();

        if(!pid) {
            linuxCommand(arguments[0],arguments);
            printf(RED "ERROR: INVALID COMMAND\n" RESET);
            abort();
        }

        if(groundState == 0) {
            waitid(P_PID, pid, &childstat, WEXITED);
        }

    }

}
