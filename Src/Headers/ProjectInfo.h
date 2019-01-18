/**
 * File description
 *      Created on: 10 December 2018
 *   Last modified: 10 December 2018
 *         Authors: sonapraneeth-a
 *         Details: Header for constant variables describing the project information
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 10-12-2018               sonapraneeth-a      - Creation of the file
 *                                              - Added __PROJECT_VERSION__ variable
 *                                              - Added __PROJECT_NAME__ variable
 */


#ifndef PROJECT_INFO_H
#define PROJECT_INFO_H

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAJOR_VERSION 0
#define MINOR_VERSION 1
#define PATCH_VERSION 0

#define __PROJECT_VERSION__ STR(MAJOR_VERSION) "." \
                            STR(MINOR_VERSION) "." \
                            STR(PATCH_VERSION)
#define __PROJECT_NAME__ "Data Structures and Algorithms"

#endif // PROJECT_INFO_H
