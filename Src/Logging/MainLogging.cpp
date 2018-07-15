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
// #include "Logging.h"

using namespace BaseLogging;

void
BaseLogRegisterFail()
{
    SET_LOG_LEVEL(11);
    LOG(1, "Message\n");
    for (int index = 0; index < 100; ++index)
    {
        LOG(1, "Message " << index << "\n");
    }
}

void
BaseLogRegister()
{
    SET_LOG_LEVEL(2);
    LOG(1, "Message\n");
    for (int index = 0; index < 100; ++index)
    {
        LOG(1, "Message " << index << "\n");
    }
    return;
}

int main()
{
    // BaseLogRegisterFail();
    BaseLogRegister();
    return 0;
}