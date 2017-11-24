#include "FileProcessing.h"

#include "../utils/Constants.h"

#include <stdio.h>

void createFile(char* path) {

    FILE* fptr;
    fptr = fopen(path, "w");

    if(fptr == NULL) {
        printf("ERROR: FILE CREATION\n");
        return;
    }

    fclose(fptr);
}

FILE* openFile(char* path) {

    FILE* fptr = fopen(path, "r");

    return fptr;
}

void printFile(char* path) {

    char line[MAX_LENGTH + 1];
    FILE* fptr;
    fptr = fopen(path, "r");

    if(fptr == NULL) {
        printf("ERROR: FILE PRINTING\n");
        return;
    }

    while(fgets(line, sizeof(line), fptr)){
        printf("%s", line);
    }

    fclose(fptr);
}

void appendFile(char* path, char* message) {

    FILE* fptr;
    fptr = fopen(path, "a");

    if(fptr == NULL) {
        printf("ERROR: FILE APPENDING\n");
        return;
    }

    if(message != NULL) {
        fprintf(fptr, "%s\n", message);
    }

    fclose(fptr);
}
