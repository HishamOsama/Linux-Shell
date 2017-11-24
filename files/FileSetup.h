#ifndef FILESETUP_H
#define FILESETUP_H

/**
 * This function is responsible for creating
 * History and Log files in the working directory
 * of the project
 */
void setupFiles();

/**
 * This function is returing the absolute path
 * of the history file
 *
 * @return absolute path of the history file
 */
char* getHistoryFilePath();

/**
 * This function is returing the absolute path
 * of the log file
 *
 * @return absolute path of the log file
 */
char* getLogFilPath();

#endif // FILESETUP_H
