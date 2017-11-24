#ifndef UTILS_H
#define UTILS_H

/**
 * This function checks if the command
 * length lies in the specific allowed
 * range or not
 *
 * @param command User command
 * @return
 */
int isValidLength(char* command);

/**
 * This function is responsible for calling
 * the appropriate functions to parse the
 * user command
 *
 * @param command User command
 * @return
 */
int isComment(char* command);

/**
 * This function is responsible for calling
 * the appropriate functions to parse the
 * user command
 *
 * @param command User command
 * @return
 */
char* trimCommand(char* command);

/**
 * This function is responsible for calling
 * the appropriate functions to parse the
 * user command
 *
 * @param command User command
 */
int getLastCharIndex(char* command);

/**
 * This function is responsible splitting
 * the user command to a list of arguments
 *
 * @param command User command
 * @param delimiter String to split on
 * @param arguments Arguments of the command
 * to be filled
 */
void splitCommand(char* command, char* delimiter, char* arguments[]);

/**
 * This function is responsible counting
 * the user command arguments number
 *
 * @param command User command
 * @param delimiter String to split on
 */
int countArguments(char* command, char* delimiter);

/**
 * This function is responsible for setting
 * the state of the execution which is either
 * background or foreground
 *
 * @param state Variable indicating the state
 */
void setGroundStateVariable(int state);

/**
  * This function is responsible for getting
 * the state of the execution which is either
 * background or foreground
 *
 * @return variable indicating the state
 */
int getGroundStateVariable();

#endif // UTILS_H
