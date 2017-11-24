#ifndef VARIABLES_H
#define VARIABLES_H

/**
 * This function is responsible for
 * searching for the value of the variable
 * in the environment variables or the
 * session variables
 *
 * @param key Key of the variable
 */
char* lookupVariable(char* key);

/**
 * This function is responsible for trying
 * to set the command as a variable assignment
 * and grabs the required data
 *
 * @param equality User command in equality form
 */
int setVariable(char* equality);

/**
 * This function is responsible for calling
 * printing the session variables
 */
void printVariables();

/**
 * This function is a helper method in the
 * substituting process
 *
 * @param count Pointer to the next position
 * for data adding
 * @param value Value to susbtitue with
 * @param output Substituted command
 * @return new value of the count
 */
int addValue(int count, char* value, char* output);

/**
 * This function is responsible for susbtituting
 * the values of the variables in the command
 *
 * @param command User command
 * @return susbtituted command
 */
char* substituteVariables(char* command);

/**
 * This function is responsible checking
 * the synatax of the key
 *
 * @param key Key of the equality
 * @return variable indicating the synatx of
 * the key
 */
int checkKey(char* key);

/**
 * This function is responsible checking
 * the synatax of the value
 *
 * @param value Value of the equality
 * @return variable indicating the synatx of
 * the value
 */
int checkValue(char* value);

/**
 * This function is responsible for special
 * trimming of a string
 *
 * @param value String to be trimmed
 * @return trimmed string
 */
char* trimValue(char* value);

/**
 * This function is responsible for modifying
 * the environment variables
 *
 * @param key Key of the equality
 * @param value Value of the equality
 */
void modifyEnvironmentVariables(char* key, char* value);

#endif // VARIABLES_H
