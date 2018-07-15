//
// Created by pranas on 7/15/2018.
//

#include "Logging.h"

// Reference: https://stackoverflow.com/questions/7092765/what-does-it-mean-to-have-an-undefined-reference-to-a-static-member
std::string Logging::Logger::_LogFilename = "Main.log";
bool Logging::Logger::_LogToFile = false;
bool Logging::Logger::_LogToConsole = true;
Logging::Levels Logging::Logger::_WarnLevels = {1, 1, 0, 3};
std::string Logging::Logger::_Default_LogPrint = "[" + GetCurrentTime() + "]";
std::stringstream Logging::Logger::_Warning_Message;

// Reference: https://stackoverflow.com/questions/8130066/static-member-functions-error-how-to-properly-write-the-signature
void
Logging::Logger::SetConfig(std::string Logfilename,
                           bool LogToFile,
                           bool LogToConsole)
{
    _LogFilename = Logfilename;
}

void
Logging::Logger::PrintConfig()
{
    std::cout << "===== LOG Configuration =====" << "\n";
    std::cout << "Logging to console: " << (_LogToConsole ? "Enabled" : "Not enabled") << "\n";
    std::cout << "   Logging to file: " << (_LogToFile ? "Enabled" : "Not enabled") << "\n";
    if (_LogToFile)
    {
        std::cout << "          Log file: " << _LogFilename << "\n";
    }
}

void
Logging::Logger::Warning(unsigned int level, std::string Message)
{
    if (level >= _WarnLevels.MinLevel && level <= _WarnLevels.MaxLevel)
    {
        std::cout << "[WARNING]" << Message << "\n";
    }
}

void
Logging::Logger::Warning(unsigned int level, std::stringstream Message)
{
    if (level >= _WarnLevels.MinLevel && level <= _WarnLevels.MaxLevel)
    {
        std::cout << "[WARNING]" << Message.str() << "\n";
    }
}