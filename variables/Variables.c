#include "Variables.h"

#include "../parser/CommandParser.h"
#include "../parser/Utils.h"
#include "../utils/Constants.h"
#include "../executor/CommandExecutor.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keysTable[100][100];
char valuesTable[100][100];
int count = 0;

char* lookupVariable(char* key) {

    int i;
    for(i = count - 1; i >= 0; i--) {
        if(strcmp(keysTable[i], key) == 0) {
            return valuesTable[i];
        }
    }

    if(getenv(key) != NULL) {
        return getenv(key);
    }

    return EMPTY_STRING;
}

int setVariable(char* equality) {

    char tempEquality[MAX_LENGTH];
    strcpy(tempEquality, equality);

    if(countArguments(tempEquality, EQUAL) != 2) {
        return 0;
    }

    char* key = strtok(equality, EQUAL);
    char* value = strtok(NULL, EQUAL);

    if(checkKey(key) == 1 && checkValue(value) != 0) {
        strcpy(keysTable[count], key);
        value = trimValue(value);
        strcpy(valuesTable[count], value);
        modifyEnvironmentVariables(key, value);
        count++;
        printf(GRN "Successful Assignment\n" RESET);
        return 1;
    }

    return 0;
}

void printVariables() {

    int i;
    for(i = 0; i < count; i++) {
        printf("KEY[%d]: %s, ", i, keysTable[i]);
        printf("VALUE[%d]: %s\n", i, valuesTable[i]);
    }

}

int addValue(int count, char* value, char* output) {
    int j;
    for(j = 0; j < strlen(value); j++) {
        output[count] = value[j];
        count++;
    }
    return count;
}

char* substituteVariables(char* command) {

    char* output = malloc(MAX_LENGTH);

    int i;
    int count = 0;
    for(i = 0; i < strlen(command); i++) {
        if(command[i] == VARIABLE_IDENTIFIER) {
            char tempkey[100];
            int tempCount = 0;
            i++;
            while(i < strlen(command) && (isalpha(command[i]) || isdigit(command[i]))) {
                tempkey[tempCount] = command[i];
                tempCount++;
                i++;
            }
            i--;
            char* tempValue = lookupVariable(tempkey);
            count = addValue(count, tempValue, output);
        } else if (command[i] == HOME_IDENTIFIER) {
            char* tempValue = getenv("HOME");
            count = addValue(count, tempValue, output);
        } else {
            output[count] = command[i];
            count++;
        }
    }

    output[count] = STRING_TERMINATOR;
    return output;
}

int checkKey(char* key) {

    int i;

    for(i = 0; i < strlen(key); i++) {
        if(i == 0) {
            if(isalpha(key[i]) == 0 && key[i] != '_') {
                return 0;
            }
        } else {
            if(isdigit(key[i]) == 0 && isalpha(key[i]) == 0 && key[i] != '_') {
                return 0;
            }
        }
    }

    return 1;
}

int checkValue(char* value) {

    int i,length = strlen(value);

    if(value[0] == '\"' || value[length - 1] == '\"') {
        if(value[0] == '\"' && value[length - 1] == '\"' && length != 1) {
            return 1;
        } else {
            return 0;
        }
    }

    for(i = 0; i < strlen(value); i++) {
        if(isspace(value[i]) != 0) {
            return 0;
        }
    }

    return 1;
}

char* trimValue(char* value) {

    char* trimmedValue = value;
    int length = strlen(value);

    if(value[0] == '\"' && value[length - 1] == '\"') {
        trimmedValue[length - 1] = '\0';
        trimmedValue++;
    }

    return trimmedValue;
}

void modifyEnvironmentVariables(char* key, char* value) {
    if(getenv(key) == NULL) {
        return;
    }
    setenv(key,value,1);
}
