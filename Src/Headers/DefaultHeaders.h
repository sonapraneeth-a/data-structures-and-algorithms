/**
 * File description
 *      Created on: 10 December 2018
 *   Last modified: 10 December 2018
 *         Authors: sonapraneeth-a
 *         Details: Header for including all other headers
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 10-12-2018               sonapraneeth-a      - Creation of the file
 *                                              - Added StandardHeaders.h
 *                                              - Added ProjectInfo.h
 *                                              - Added code for printing project
 *                                                information
 */

#ifndef DEFAULT_HEADERS_H
#define DEFAULT_HEADERS_H

#include <iterator>
#include <sstream>
#include <cstddef>

#include "StandardHeaders.h"
#include "ProjectInfo.h"


 /*!
  * @brief   Prints project related information on screen
  * @details Details printed are name, project version, OS and compiler version
  */
void 
PrintProjectInfo()
{
    std::cout << "Project Details\n";
    std::cout << "========================================\n";
    std::cout << "   Name: " << __PROJECT_NAME__ << "\n";
    std::cout << "Version: " << __PROJECT_VERSION__ << "\n";
    // Reference: https://blog.kowalczyk.info/article/j/guide-to-predefined-macros-in-c-compilers-gcc-clang-msvc-etc..html
    std::cout << "OS Details\n";
    std::cout << "----------------------------------------\n";
#if defined(_WIN64) || defined(_WIN32)
    std::cout << "Windows\n";
#elif defined(__linux__)
    std::cout << "Linux\n";
#elif defined(__APPLE__)
    std::cout << "Mac OS\n";
#endif
    std::cout << "Compiler Details\n";
    std::cout << "----------------------------------------\n";
#if defined (_MSC_VER)
    // code specific to Visual Studio compiler
    std::cout << "Compiler: Microsoft Visual C++ Compiler\n";
    std::cout << " Version: " << _MSC_VER << _MSC_FULL_VER << "\n";
#endif
#if defined (__GNUC__)
    // code specific to GNC GCC compiler
    std::cout << "Compiler: GNU GCC Compiler\n";
    std::cout << " Version: " << __GNUC__ << __GNUC_MINOR__ << __GNUC_PATCHLEVEL__ << "\n";
#endif
}

void
PrintHeading(
        const std::string& content,
        unsigned short int level = 1
        )
{
    size_t length = content.size();
    std::string character = ( level == 1 ? "=" : "-" );
    std::ostringstream os;
    std::fill_n(std::ostream_iterator<std::string>(os), length, character);
    std::cout << os.str() << "\n";
    std::cout << content << "\n";
    std::cout << os.str() << "\n";
    std::cout.flush();
}

#endif // DEFAULT_HEADERS_H
