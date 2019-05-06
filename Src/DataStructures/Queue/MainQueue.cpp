/**
 * File description
 *
 *        Filename: MainQueue.cpp
 *      Created on: 20 March 2018
 *   Last modified: 18 January 2019
 *         Authors: sonapraneeth-a
 *         Details: File for main executable of the project - queue
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018               sonapraneeth-a      - Creation of the file
 * 18-01-2019               sonapraneeth-a      - Added main()
 */


#include "DefaultHeaders.h"
#include "NotImplementedException.h"

#include "Queue.h"

/**
 * @brief
 * @details
 *
 * @return
 */
void
RunQueue_Constructors()
{
    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
        );
}

/**
 * @brief
 * @details
 *
 * @return
 */
void
RunQueue_Enqueue()
{
    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
    );
}

/**
 * @brief
 * @details
 *
 * @return
 */
void
RunQueue_Dequeue()
{
    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
    );
}

/**
 * @brief
 * @details
 *
 * @return
 */
void
RunQueue_Size()
{
    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
    );
}

/**
 * @brief
 * @details
 *
 * @return
 */
void
RunQueue_IsEmpty()
{
    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
    );
}

/**
 * @brief
 * @details
 *
 * @return
 */
void
RunQueue_HeadValue()
{
    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
    );
}

/**
 * @brief
 * @details
 *
 * @return
 */
void
RunQueue_TailValue()
{
    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
    );
}


/**
 * @brief   Code for manual testing of Queue module
 * @details
 *
 * @return
 */
int
main()
{
    PrintProjectInfo();
    std::cout << "\n";

    PrintHeading("Sample code for Queue module", 1);

    RunQueue_Constructors();
    RunQueue_Enqueue();
    RunQueue_Dequeue();
    RunQueue_Size();
    RunQueue_IsEmpty();
    RunQueue_HeadValue();
    RunQueue_TailValue();

    return 0;
}
