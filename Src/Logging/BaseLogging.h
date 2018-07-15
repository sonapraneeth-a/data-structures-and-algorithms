/**
 *      Created on: 24 January 2018
 *   Last modified: 04 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for logging library
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 24-01-2018             Sona Praneeth Akula   - Creation of the file
 * 04-07-2018             Sona Praneeth Akula   -
 */

#ifndef LOGGING_H
#define LOGGING_H


extern bool LOG_ACTIVATE;
extern int LOG_LEVEL;
extern string logFile;
extern bool logFileOpen;
extern ofstream logOutFile;
extern stringstream logMessage;
extern stringstream logExceptionMessage;

#define LOG_MSG(level) if(LOG_ACTIVATE && level <= LOG_LEVEL) logMessage
#define PRINT_LOG(level, message) LOG_MSG(level) << "[" << get_current_time() << "]" \
                                    << " [" << __func__ << "]" \
                                    << " Line " << __LINE__ << ": " << message; \
                                    PRINT_LOG_MESSAGE(level);

#define SET_LOG setLog()
#define SET_LOG_LEVEL(level) setLog(level)
#define SET_LOG_TO_FILE(level, filename) setLog(level); setLog(filename)
#define SET_LOG_FILE(filename) setLog(filename)
#define LOG_PRINT(level, logMessage) printLogMessage(level, logMessage)
#define PRINT_LOG_MESSAGE(level) printLogMessage(level, logMessage)

/**
 * @brief Clear the log stringstream
 *
 * @param logMessageToPrint
 *
 */
void clearLog(stringstream &logMessageToPrint);

/**
 * @brief Activate logging for the program
 *
 */
void setLog();

/**
 * @brief Set the log level for logging purpose
 *
 * @param [int] level - 1,2,3.
 *              1 - highest preference message. 3 - least preference message
 *
 */
void setLog(int level);

/**
 * @brief Set the log level for logging purpose
 *
 * @param [string] filename - Name of the file to which log statements have to be printed
 *
 */
void setLog(string filename);

/**
 * @brief Prints log message (stringstream) to file/console
 *
 * @param [int] level
 * @param [stringstream] logMessageToPrint
 *
 */
void printLogMessage(int level, stringstream &logMessageToPrint);

/**
 * @brief Prints log message (string) to file/console
 *
 * @param [int] level
 * @param [string] logMessageToPrint
 */
void printLogMessage(int level, string logMessageToPrint);

/**
 * @brief Deactivate logging for the program
 *
 */
void unsetLog();



#endif //LOGGING_H
