#ifndef FILEPROCESSING_H
#define FILEPROCESSING_H

#include <stdio.h>

/**
 * This function is responsible for creating
 * a new file
 *
 * @param path Path of the file to be created
 */
void createFile(char* path);

/**
 * This function is responsible for opening
 * an existing file or creating a new one
 *
 * @param path Path of the file to be opened
 * @return pointer to the opened file
 */
FILE* openFile(char* path);

/**
 * This function is responsible for appending
 * data to an existing file or creating a new one
 * and appending data to it
 *
 * @param path Path of the file to append message
 * @param message Message to be apended to the file
 */
void appendFile(char* path, char* message);

/**
 * This function is responsible for printing
 * the contents of a file
 *
 * @param path Path of the file to print
 */
void printFile(char* path);

#endif // FILEPROCESSING_H
