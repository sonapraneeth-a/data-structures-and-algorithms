# Rules

**Last updated:** 15 October, 2018

This document is a draft of coding guidelines to be followed for contributing
to this repository. Currently, the code is being modified to adhere to the
guidelines in the document. If you find any guideline missing from the document,
please raise a PR updating it.

## General

- Please ensure that all the code is within 80 columns. Please set your editors
  accordingly
- Casing Examples:
    - CapitalCase
    - camelCase
    - underscore_separation

## Variables

- Use Capital casing for variable names, class names, function names
- Use camelCase casing for function input parameters
- Use ```_``` in front of private variable names
- Use ```__``` in front of local variable names

## Classes

- All private variables and function names start with an ```_``` followed by
  CapitalCasing convention
    - *Example:* ```_Array```
- All public variables and function names follow CapitalCasing
    - *Example:* ```PushBack```
- Use ```__``` in front of local variable names in functions
- For functions returning boolean values, add Is to the name of the functions
    - *Example:* ```IsEmpty```
- If a function signature has been introduced in a class but not implemented,
  throw a ```NotImplementedException```
- If tests are not written for a function which is implemented, then add a
  comment with the following line
    - ```// @todo Need to add tests for this function```
    - This @todo can be introduced before @brief in the comment section of the
      function. See comment rules for more details

## Functions

- Format
```cpp
template if any
return type of the function
function name (
  param1
  param2
  ...
)
{
  // Some code
}
```
- *Example:*
```cpp
template<typename T>
void
Array<T>::Get (
    ULLI index
)
{
  // Some code
}
```

## Comment rules

- Write detailed comments for every line of code if it is not obvious to
  understand
- Write references from internet (or) any book if you have used any with a
  prefix "Reference: "
    - *Example:* ```// Reference: <Information/URL related to the reference>```
- Add a todo with "@todo" prefix
    - *Example:* ```@todo Fix this issue```
- Must parameters for commenting a function
    - @brief
        - One line description of the function
    - @details
        - Detailed information about what the function does
        - Time and space complexity are must
    - @param
        - Parameter to the function
        - Format [data type] parameter name - one line info about the parameter
    - @return
        - Parameter returned from the function
        - Format: [data type] return variable name (Optional) - one line info
          about the return variable
    - *Example:*
    ```cpp
    /**
     * @todo    This line would be necessary if there is anything that is left
                to be done/implemented/fixed for the function
     * @brief   This is a brief description about the function
     * @details This is a detailed description about the function. This can be
     *          in a single line or extend to multiple lines. But the
     *          description should be detailed enough for the programmers to
     *          understand what the function does
     *
     * @param   [int] value - Value to be used
     * @return  [int] Value obtained after performing some operation
     */
    ```
- Update Changelog present at the top of the file for every change you make
  - Please use the below format for updating Changelog (add just the last lines)
  ```cpp
  /**
   * Changelog
   *
   * Date (DD-MM-YYYY)    Author              Update
   * <date>               <github-username>   - <multiple points related to the
   *                                            change you made>
   */
  ```
- Header comments
  - Add your name in the ```Authors``` section at the first comment block present
    at the top of the file if you have modified the file
  - Update your name in CONTRIBUTING.md file with the following details if your
    information is not present
  ```txt
    - Name: <your-name>
      Github handle: <github-username>
      Email: <your-email-id>
  ```
  - Similarly, update ```Last modified``` at the first comment block present at
    the top of the file
  - Format
    ```cpp
    /**
     *      Created on: <date-created>
     *   Last modified: <date-last-modified>
     *         Authors: author 1 your name <email id>
     *                  author 2 your name <email id>
     *         Details: detail regarding the file
     */
    ```

## Writing test cases

- ```class <ClassName/FunctionName>Test : public ::testing::Test```
- ```<ClassName>Test_<FunctionName>```
- ```<FunctionName>Test```