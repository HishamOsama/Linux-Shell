#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

/**
 * This function is responsible for logging
 * the state of the child process
 */
void logState();

/**
 * This function is responsible for executing
 * the user command
 *
 * @param command User command
 * @param arguments Arguments List of the user command
 */
void execute(char* command, char* arguments[]);

#endif // COMMANDEXECUTOR_H
