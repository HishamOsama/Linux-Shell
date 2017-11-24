#ifndef UTILS_H
#define UTILS_H

/**
 * This function is responsible for implementing
 * the cd command to change the current working
 * directory
 *
 * @param path Path of the destination directory
 */
void cd(char* path);

/**
 * This function is responsible for implementing
 * the echo command to print the messages of the
 * user
 *
 * @param command Command entered by the user
 */
void echo(char* command);

/**
 * This function is responsible for executing
 * user command where various linux commands
 * could be executed
 *
 * @param program User program name
 * @param arguments Arguments List of the user command
 */
void linuxCommand(char* program,char* arguments[]);


#endif // UTILS_H
