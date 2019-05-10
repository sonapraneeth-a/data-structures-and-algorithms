/**
 * File description
 *
 *        Filename: MainNode.cpp
 *      Created on: 15 January 2019
 *   Last modified: 16 January 2019
 *         Authors: sonapraneeth-a
 *         Details: File for main executable of the project - node
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 15-01-2019               sonapraneeth-a      - Creation of the file
 *                                              - Added code for RunArray_Constructors()
 * 16-01-2019               sonapraneeth-a      - Added code for RunArray_Data()
 *                                              - Added code for RunArray_Next()
 *                                              - Added code for RunArray_ToString()
 *                                              - RunArray_Next() and RunArray_ToString()
 *                                                are not yet implemented
 */

#include "DefaultHeaders.h"
#include "NotImplementedException.h"

#include "Node.h"

#if defined(_MSC_VER)
    #define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

/**
 * @brief   Code for testing Node constructors
 * @details
 *
 * @return
 */
void
RunNode_Constructors()
{
    PrintHeading("Running code for Node Constructors()", 2);

    std::cout << "Constructor(1) --> Node()\n";
    DS::Node<int> Node_001;
    std::cout << "          Node_001: " << Node_001 << "\n";

    std::cout << "Constructor(1) --> Node()\n";
    DS::Node<char> Node_002;
    std::cout << "          Node_002: " << Node_002 << "\n";

    std::cout << "Constructor(1) --> Node()\n";
    DS::Node<std::string> Node_003;
    std::cout << "          Node_003: " << Node_003 << "\n";

    std::cout << "Constructor(2) --> Node()\n";
    DS::Node<int> Node_101(5);
    std::cout << "          Node_101: " << Node_101 << "\n";

}

/**
 * @brief   Code for testing Node Data()
 * @details
 *
 * @return
 */
void
RunNode_Data()
{
    PrintHeading("Running code for Node Data()", 2);

    std::cout << "Data(1) --> Node()\n";
    DS::Node<int> Node_001;
    std::cout << "          Node_001: " << Node_001 << "\n";
    Node_001.Data(2);
    std::cout << "          Node_001: " << Node_001 << "\n";

    std::cout << "Data(1) --> Node()\n";
    DS::Node<char> Node_002;
    std::cout << "          Node_002: " << Node_002 << "\n";
    Node_002.Data('c');
    std::cout << "          Node_002: " << Node_002 << "\n";

    std::cout << "Data(1) --> Node()\n";
    DS::Node<std::string> Node_003;
    std::cout << "          Node_003: " << Node_003 << "\n";
    Node_003.Data("string");
    std::cout << "          Node_003: " << Node_003 << "\n";

    std::cout << "Data(2) --> Node()\n";
    DS::Node<int> Node_101(5);
    std::cout << "          Node_101: " << Node_101 << "\n";
    Node_101.Data(10);
    std::cout << "          Node_101: " << Node_101 << "\n";
}

/**
 * @brief   Code for testing Node Next()
 * @details
 *
 * @return
 */
void
RunNode_Next()
{
    PrintHeading("Running code for Node Next()", 2);

    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
        );
}

/**
 * @brief   Code for testing Node ToString()
 * @details
 *
 * @return
 */
void
RunNode_ToString()
{
    PrintHeading("Running code for Node ToString()", 2);

    throw Exception::NotImplementedException(
        std::string(__PRETTY_FUNCTION__) + " is not implemented"
    );
}

/**
 * @brief   Code for manual testing of Node module
 * @details
 *
 * @return
 */
int
main()
{
    PrintProjectInfo();
    std::cout << "\n";

    PrintHeading("Sample code for Node module", 1);

    RunNode_Constructors();
    RunNode_Data();
    RunNode_Next();
    RunNode_ToString();

    return 0;
}
