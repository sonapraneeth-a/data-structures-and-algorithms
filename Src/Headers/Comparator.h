/**
 *      Created on: 09 July 2018
 *   Last modified: 15 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Comparator Header file
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 09-07-2018             Sona Praneeth Akula   - Creation of file
 * 15-07-2018             Sona Praneeth Akula   - Added Comparator functions
 */

#ifndef COMPARATOR_H
#define COMPARATOR_H

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool LesserComparator(T &first, T &second)
{
    return first <= second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool GreaterComparator(T first, T second)
{
    return first >= second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool StrictLesserComparator(T first, T second)
{
    return first < second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool StrictGreaterComparator(T first, T second)
{
    return first > second;
}

/**
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
bool EqualsComparator(T &first, T &second)
{
    return first == second;
}


#endif //COMPARATOR_H
