#include "FileSetup.h"

#include "FileProcessing.h"
#include "../utils/Constants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* historyFilePath;
char* logFilePath;

void setupFiles() {

    char* projectPath = getenv("PWD");

    historyFilePath = malloc(MAX_LENGTH);
    logFilePath = malloc(MAX_LENGTH);

    // History File
    strcpy(historyFilePath, projectPath);
    strcat(historyFilePath, "/output/history");

    // Log File
    strcpy(logFilePath, projectPath);
    strcat(logFilePath, "/output/log");

    // Create Files
    appendFile(historyFilePath, NULL);
    createFile(logFilePath);
}

char* getHistoryFilePath() {
    return historyFilePath;
}

char* getLogFilPath() {
    return logFilePath;
}
