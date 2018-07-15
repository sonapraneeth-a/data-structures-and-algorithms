/**
 *      Created on: 24 January 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for Logging library
 */

/**
 * ChangeLog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 24-01-2018             Sona Praneeth Akula   - Creation of the file
 * 15-07-2018             Sona Praneeth Akula   - Lifted the code I created long ago from
 *                                                https://github.com/vvanirudh/tum_ardrone_iitb/blob/phase02-fix/src/controlUI/LogUtility/LogUtility.hpp
 */

#ifndef LOGGING_H
#define LOGGING_H

#include "DefaultHeaders.h"

extern bool LOG_ACTIVATE;
extern unsigned int LOG_LEVEL;
extern std::string LogFile;
extern bool LogFileOpen;
extern std::ofstream LogOutFile;
extern std::stringstream LogMessage;
extern std::stringstream LogExceptionMessage;

enum STATUS { INFO, DEBUG, WARNING, ERROR, CRITICAL };

#define LOG_MSG(Level) if(LOG_ACTIVATE && Level <= LOG_LEVEL) LogMessage
#define LOG(Level, message) LOG_MSG(Level) << "[" << GetCurrentTime() << "]" \
                                    << " [" << __func__ << "]" \
                                    << " Line " << __LINE__ << ": " << message; \
                                    PRINT_LOG_MESSAGE(Level);
                                    
#define SET_LOG RegisterLog()
#define SET_LOG_LEVEL(Level) RegisterLog(Level)
#define SET_LOG_TO_FILE(Level, filename) RegisterLog(Level); RegisterLog(filename)
#define SET_LOG_FILE(filename) RegisterLog(filename)
#define LOG_PRINT(Level, LogMessage) PrintLogMessage(Level, LogMessage)
#define PRINT_LOG_MESSAGE(Level) PrintLogMessage(Level, LogMessage)

/**
 * @brief Clear the Log stringstream
 *
 * @param LogMessageToPrint
 *
 */
void ClearLog(std::stringstream &LogMessageToPrint);

/**
 * @brief Register the Log Level for Logging purpose
 *
 * @param [int] Level - 1,2,3.
 *              1 - highest preference message. 3 - least preference message
 * @param [string] filename - Name of the file to which Log statements have to be printed
 */
void RegisterLog(unsigned int Level = 0,
                 unsigned int Status = STATUS::CRTICAL,
                 std::string filename = "");

/**
 * @brief Prints Log message (stringstream) to file/console
 *
 * @param [int] Level
 * @param [stringstream] LogMessageToPrint
 *
 */
void PrintLogMessage(unsigned int Level, std::stringstream &LogMessageToPrint);

/**
 * @brief Prints Log message (string) to file/console
 *
 * @param [int] Level
 * @param [string] LogMessageToPrint
 */
void PrintLogMessage(unsigned int Level, std::string LogMessageToPrint);

/**
 * @brief Deactivate Logging for the program
 *
 */
void DeregisterLog();



#endif //LOGGING_H
