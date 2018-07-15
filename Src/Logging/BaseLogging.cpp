/**
 *      Created on: 24 January 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for Logging library
 */

/**
 * ChangeLog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 24-01-2018             Sona Praneeth Akula   - Creation of the file
 * 15-07-2018             Sona Praneeth Akula   - Lifted the code I created long ago from
 *                                                https://github.com/vvanirudh/tum_ardrone_iitb/blob/phase02-fix/src/controlUI/LogUtility/LogUtility.hpp
 */

#include "BaseLogging.h"

bool LOG_ACTIVATE = false;          /*!< boolean variable to start Logging. DEFAULT: "false" */
unsigned int LOG_LEVEL = 0;          /*!< level of Logging messages to be Printed. DEFAULT: "1" */
unsigned int LOG_STATUS = STATUS::CRITICAL;
std::string LogFile = "Log/Run.log"; /*!< If Logging is set to file. DEFAULT: "Log/myLog.txt" */
bool LogFileOpen = false;   /*!< boolean variable to check if Log file is open. DEFAULT: "false" */
std::ofstream LogOutFile;            /*!< stream operator for writing to Log file */
std::stringstream LogMessage;        /*!< stream for storing Log messages */
std::stringstream LogExceptionMessage;       /*!< stream for storing exception messages */

void RegisterLog(unsigned int level,
                 unsigned int Status,
                 std::string filename)
{
    if( !(level>=0 && level<=3) )
    {
        LogExceptionMessage.str(std::string());
        LogExceptionMessage << "\nWrong Log level " << level << " used.\n";
        LogExceptionMessage << "Please use Log level between 1 and 3.\n";
        LogExceptionMessage << "Highest preference message has level 1.\n";
        //throw LogExceptionMessage.str();
        std::cout << LogExceptionMessage.str() << "\n";
        exit(EXIT_FAILURE);
    }
    LOG_ACTIVATE = true; LogMessage.str(std::string());
    LOG_LEVEL = level;
    LOG_MSG(0) << "LOG IS ACTIVATED WITH LEVEL " << LOG_LEVEL << ".\n";
    if (filename != "")
    {
        LogFile = filename;
        LogFileOpen = true;
        LogOutFile.open(LogFile.c_str(), std::ofstream::out);
        LOG_MSG(0) << "LOG TO FILE \"" << LogFile << "\" ACTIVATED.\n";
    }
    PrintLogMessage(0, LogMessage);
}

void PrintLogMessage( unsigned int level,
                      std::stringstream &LogMessageToPrint)
{
    if (LOG_ACTIVATE && !LogFileOpen && level <= LOG_LEVEL)
    {
        std::cout << "[   LOG] " << LogMessageToPrint.str();
        ClearLog(LogMessageToPrint);
    }
    else if (LOG_ACTIVATE && LogFileOpen && level <= LOG_LEVEL)
    {
        std::streambuf *coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(LogOutFile.rdbuf());
        std::cout << "[   LOG] " << LogMessageToPrint.str();
        ClearLog(LogMessageToPrint);
        std::cout.rdbuf(coutbuf);
    }
    else
    {
        ClearLog(LogMessageToPrint);
    }
}

void PrintLogMessage( unsigned int level,
                      std::string LogMessageToPrint)
{
    if( !(level>=0 && level<=3) )
    {
        LogExceptionMessage.str(std::string());
        LogExceptionMessage << "\nWrong Log level " << level << " used.\n";
        LogExceptionMessage << "Please use Log level between 1 and 3.\n";
        LogExceptionMessage << "Highest preference message has level 1.\n";
        //throw LogExceptionMessage.str();
        std::cout << LogExceptionMessage.str() << "\n";
        exit(EXIT_FAILURE);
    }
    if (LOG_ACTIVATE && !LogFileOpen && level <= LOG_LEVEL)
    {
        std::cout << "[   LOG] " << LogMessageToPrint;
    }
    else if (LOG_ACTIVATE && LogFileOpen && level <= LOG_LEVEL)
    {
        std::streambuf *coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(LogOutFile.rdbuf());
        std::cout << "[   LOG] " << LogMessageToPrint;
        LogMessageToPrint = "";
        std::cout.rdbuf(coutbuf);
    }
    else
    {
        LogMessageToPrint = "";
    }
}

void ClearLog(std::stringstream &LogMessageToPrint)
{
    LogMessageToPrint.str(std::string());
}

void DeregisterLog()
{
    LOG_ACTIVATE = false;
    PrintLogMessage(0, "LOG DEACTIVATED.\n");
    if(LogOutFile.is_open())
    {
        LogOutFile.close();
    }
}
