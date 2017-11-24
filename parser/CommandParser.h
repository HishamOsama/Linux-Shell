#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

/**
 * This function is responsible for calling
 * the appropriate functions to parse the
 * user command
 *
 * @param command User command
 */
void parse(char* command);

/**
 * This function is responsible for returning
 * the parsed command
 *
 * @return parsed command
 */
char* getCommand();

/**
 * This function is responsible for returing
 * the command arguments
 *
 * @param arguments List to be filled with
 * the arguments of the command
 */
void getCommandArguments(char* arguments[]);

/**
 * This function is responsible for returing
 * the execution state of the command whether
 * it is backgroud or foreground

 * @return execution state of the command
 */
int getGroundState();

#endif // COMMANDPARSER_H
