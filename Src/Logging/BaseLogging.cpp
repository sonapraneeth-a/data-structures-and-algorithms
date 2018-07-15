/**
 *      Created on: 24 January 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for logging library
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 24-01-2018             Sona Praneeth Akula   - Creation of the file
 * 15-07-2018             Sona Praneeth Akula   - Lifted the code I created long ago from
 *               
 */

#include "Logging.h"

bool LOG_ACTIVATE = false;          /*!< boolean variable to start logging. DEFAULT: "false" */
int LOG_LEVEL = 0;          /*!< level of logging messages to be printed. DEFAULT: "1" */
string logFile = "log/myLog.txt"; /*!< If logging is set to file. DEFAULT: "log/myLog.txt" */
bool logFileOpen = false;   /*!< boolean variable to check if log file is open. DEFAULT: "false" */
ofstream logOutFile;            /*!< stream operator for writing to log file */
stringstream logMessage;        /*!< stream for storing log messages */
stringstream logExceptionMessage;       /*!< stream for storing exception messages */

void setLog()
{
    LOG_ACTIVATE = true; logMessage.str(string());
    printLogMessage(0, "LOG IS ACTIVATED.\n");
}

void setLog(int level)
{
    LOG_ACTIVATE = true; logMessage.str(string());
    LOG_LEVEL = level;
    LOG_MSG(0) << "LOG IS ACTIVATED WITH LEVEL " << LOG_LEVEL << ".\n";
    printLogMessage(0, logMessage);
}

void setLog(string filename)
{
    LOG_ACTIVATE = true; logFile = filename;
    logFileOpen = true;
    logMessage.str(string());
    logOutFile.open(logFile.c_str(), ofstream::out);
    LOG_MSG(0) << "LOG TO FILE \"" << logFile << "\" ACTIVATED.\n";
    cout << "LOG TO FILE \"" << logFile << "\" ACTIVATED.\n";
    printLogMessage(0, logMessage);
}

void printLogMessage(   int level,
                        stringstream &logMessageToPrint)
{
    if (LOG_ACTIVATE && !logFileOpen && level <= LOG_LEVEL)
    {
        cout << "[   LOG] " << logMessageToPrint.str();
        clearLog(logMessageToPrint);
    }
    else if (LOG_ACTIVATE && logFileOpen && level <= LOG_LEVEL)
    {
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(logOutFile.rdbuf());
        cout << "[   LOG] " << logMessageToPrint.str();
        clearLog(logMessageToPrint);
        cout.rdbuf(coutbuf);
    }
    else
    {
        clearLog(logMessageToPrint);
    }
}

void printLogMessage(   int level,
                        string logMessageToPrint)
{
    if( !(level>=0 && level<=10) )
    {
        logExceptionMessage.str(string());
        logExceptionMessage << "\nEXCEPTION::Wrong Log level " << level << " used.\n";
        logExceptionMessage << "Please use Log level between 1 and 10.\n";
        logExceptionMessage << "Highest preference message has level 1.\n";
        throw logExceptionMessage.str();
    }
    if (LOG_ACTIVATE && !logFileOpen && level <= LOG_LEVEL)
    {
        cout << "[   LOG] " << logMessageToPrint;
    }
    else if (LOG_ACTIVATE && logFileOpen && level <= LOG_LEVEL)
    {
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(logOutFile.rdbuf());
        cout << "[   LOG] " << logMessageToPrint;
        logMessageToPrint = "";
        cout.rdbuf(coutbuf);
    }
    else
    {
        logMessageToPrint = "";
    }
}

void clearLog(stringstream &logMessageToPrint)
{
    logMessageToPrint.str(string());
}

void unsetLog()
{
    LOG_ACTIVATE = false;
    printLogMessage(0, "LOG DEACTIVATED.\n");
    if(logOutFile.is_open())
    {
        logOutFile.close();
    }
}
