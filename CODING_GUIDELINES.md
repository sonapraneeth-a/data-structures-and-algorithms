# Rules

**Last updated:** 13 December, 2018

## Indentation

We use spaces, not tabs.
Space width: 4

## Comments

- Comments at the top of C++ file
    - File description
    ```cpp
    /**
     * File description
     *
     *        Filename: Array.cpp
     *      Created on: 13 December 2018
     *   Last modified: 13 December 2018
     *         Authors: sonapraneeth-a
     *         Details: File for main executable of the project - data structures
     */
    ```
    - Changelog
    ```cpp
    /**
     * Changelog
     *
     * Date (DD-MM-YYYY)            Author               Update
     * 13-12-2018               sonapraneeth-a      - Creation of the file
     *                                              - Creation of IArray interface
     */
    ```
- Comments for functions
  ```cpp
  /**
   * @brief   Returns value present in the index^{th} block of the array
   * @details If the index given is invalid, then an "OutOfBoundsException"
   *          exception is thrown
   *
   * @tparam  T Generic parameter
   * @param   [size_t] index - Index of the array for which user wants the contents
   * @return  [T] - Value in the Array at that location. If value is not set (or)
   *                index trying to access invalid location then an exception
   *                "OutOfBoundsException" is thrown
   */
   ```


## Interfaces / Classes

- Filename containing the interface / class should match the interface / class name
- Should use PascalCasing for naming the interface / class
- The name of the interface should start with ```I```
- Private member variables start with ```_m``` in their names
- Public member variables start with ```m``` in their names
- Function names should follow PascalCasing
- Keep base implementation of interface functions in the same file
- The function signatures for class should be in .h file
- The function implementations for class should be in .cpp file

## Functions

- The input arguments to the functions should follow camelCasing
- The local variables used in the function body should start with ```__``` and
  follow small casing with underscore between words for better readability