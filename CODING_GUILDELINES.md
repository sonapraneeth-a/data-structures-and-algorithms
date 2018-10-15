# Rules

Last updated: 15 October, 2018

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
- Similarly, update ```Last modified``` at the first comment block of the file

## Writing test cases

- ```class <ClassName/FunctionName>Test : public ::testing::Test```
- ```<ClassName>Test_<FunctionName>```
- ```<FunctionName>Test```