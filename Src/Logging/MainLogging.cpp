/**
 *      Created on: 15 January 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Testing for Base Logging library
 */

/**
 * ChangeLog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 15-07-2018             Sona Praneeth Akula   - Creation of file
 *                                              - Added sample usage code
 *
 */

#include "BaseLogging.h"

void LogRegisterFail()
{
    SET_LOG_LEVEL(11);
    LOG(1, "Message\n");
    for (int index = 0; index < 100; ++index)
    {
        LOG(1, "Message " << index << "\n");
    }
}

void LogRegister()
{
    SET_LOG_LEVEL(10);
    LOG(1, "Message\n");
    for (int index = 0; index < 100; ++index)
    {
        LOG(1, "Message " << index << "\n");
    }
    return;
}

int main()
{
    // LogRegisterFail();
    LogRegister();
    return 0;
}