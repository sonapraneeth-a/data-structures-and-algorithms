//
// Created by pranas on 7/15/2018.
//

#ifndef LOGGING_H
#define LOGGING_H

#include "DefaultHeaders.h"

#define WARN(Level) if(Logging::Logger::_LogToConsole && \
                        Level >= Logging::Logger::_WarnLevels.MinLevel && \
                        Level <= Logging::Logger::_WarnLevels.MaxLevel) \
                                Logging::Logger::_Warning_Message \
                                << Logging::Logger::_Default_LogPrint <<


namespace Logging
{

    /*class Level
    {
    private:

        unsigned int _MinLevel;
        unsigned int _MaxLevel;
        unsigned int _MinPermissibleLevel;
        unsigned int _MaxPermissibleLevel;

    public:
        Level(unsigned int MinLevel,
              unsigned int MaxLevel,
              unsigned int MinPermissibleLevel,
              unsigned int MaxPermissibleLevel): _MinLevel(MinLevel), _MaxLevel(MaxLevel),
                                                 _MinPermissibleLevel(MinPermissibleLevel),
                                                 _MaxPermissibleLevel(MaxPermissibleLevel) {}
    };*/

    struct Levels
    {
        unsigned int MinLevel;
        unsigned int MaxLevel;
        unsigned int MinPermissibleLevel;
        unsigned int MaxPermissibleLevel;
    };

    #define LOG(Level, message) LOG_MSG(Level) << "[" << GetCurrentTime() << "]" \
                                            << " [" << __func__ << "]" \
                                            << " Line " << __LINE__ << ": " << message; \
                                            PRINT_LOG_MESSAGE(Level);

    class Logger
    {
    private:

        static std::string _LogFilename;
        static bool _LogToFile;
        static bool _LogToConsole;
        static Levels _WarnLevels;
        static std::string _Default_LogPrint;
        static std::stringstream _Warning_Message;

    public:

        static void SetConfig(std::string Logfilename = "Main.log",
                              bool LogToFile = false,
                              bool LogToConsole = true);
        static void PrintConfig();
        static void Warning(unsigned int level, std::string Message);
        static void Warning(unsigned int level, std::stringstream Message);

    };

}

#endif //LOGGING_H
