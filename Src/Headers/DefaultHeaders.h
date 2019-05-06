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

void
PrintProjectInfo()
{
    std::cout << "Project Details\n";
    std::cout << "========================================\n";
    std::cout << "   Name: " << __PROJECT_NAME__ << "\n";
    std::cout << "Version: " << __PROJECT_VERSION__ << "\n";
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
