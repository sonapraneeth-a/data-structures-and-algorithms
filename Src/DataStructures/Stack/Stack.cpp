/**
 * File description
 *
 *        Filename: Stack.cpp
 *      Created on: 22 March 2018
 *   Last modified: 03 April 2019
 *          Author: sonapraneeth-a
 *         Details: Implementation for stack (Imported from master branch)
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018               sonapraneeth-a        - Creation of the file
 *                                                - Added implementation of stack
 *                                                  functions
 * 24-04-2018               sonapraneeth-a        - Fixed a problem with destructor
 *                                                - Updated condition for IsEmpty()
 *                                                  function
 *                                                - Updated exception string for Pop()
 * 01-04-2018               sonapraneeth-a        - Fixed the Exceptions header path
 * 12-04-2018               sonapraneeth-a        - Added documentation for all the
 *                                                  functions
 *                                                - Fixed the constructors to not
 *                                                  add elements to top
 * 17-04-2018               sonapraneeth-a        - Added function to return size
 *                                                  of the stack
 * 15-01-2019               sonapraneeth-a        - Moved from StackNode to Node
 *                                                - Moved from ULLI to size_t for
 *                                                  size type
 * 18-01-2019               sonapraneeth-a        - Moved the code to DS namespace
 *                                                - Renamed _MaxSize variable to
 *                                                  _Capacity
 * 03-04-2019               sonapraneeth-a        - Fixed an issue in Stack destructor
 */

/**
 * @brief   Empty Stack constructor
 * @details 
 * 
 * @tparam  T Generic parameter
 */
template <typename T>
DS::Stack<T>::Stack()
{
    this->_Top = nullptr;  // _Top of the stack is null initially
    this->_Size = 0;       // _Size of the stack is also 0
    this->_Capacity = 0;   // If _Capacity is 0, then Stack has infinite capacity
}

/**
 * @brief   Constructor which fixes the maximum capacity stack can have
 * @details 
 * 
 * @tparam  T Generic parameter
 * @param   [T] value - Maximum size of the stack
 */
template <typename T>
DS::Stack<T>::Stack(T value)
{
    this->_Top = nullptr;    // _Top of the stack is null initially
    this->_Size = 0;         // _Size of the stack is also 0
    this->_Capacity = value; // Sets the maximum size of the stack
}

/**
 * @brief   Get the element at the top of the stack
 * @details If the stack is empty it throws an AccessViolationException
 * 
 * @tparam  T Generic parameter
 * @return  [T] Value which is present at the top of the stack
 */
template <typename T>
T
DS::Stack<T>::Peek()
{
    if(this->_Top != nullptr)
    {
        return this->_Top->Data();
    }
    throw Exception::AccessViolationException(
        "Stack is empty. Cannot peek elements from empty stack"
        );
}

/**
 * @brief   Removes the element from the top of the stack and returns the value
 *          which was present at the top of the stack
 * @details If the stack is empty it throws an AccessViolationException
 * 
 * @tparam  T Generic parameter
 * @return  [T] Value which was present at the top of the stack
 */
template <typename T>
T
DS::Stack<T>::Pop()
{
    if (this->_Top != nullptr)
    {
        // Get the pointer to the top of the stack
        DS::Node<T> *__TempNode = this->_Top;
        // Get the value present in the top pointer
        T value = __TempNode->Data();
        this->_Top = this->_Top->Next();
        if (this->_Size == 1)
        {
            this->_Top = nullptr;
        }
        // Free the memory for the top of the stack in order to remove the element
        delete __TempNode;
        // Reduce the size of the stack by 1
        this->_Size--;
        // Return the value which was present at the top of the stack to the
        // caller function
        return value;
    }
    // Throw exception if the stack is empty
    throw Exception::AccessViolationException(
        "Stack is empty. Cannot further pop elements."
        );
}

/**
 * @brief   Adds an element to the top of the stack
 * @details 
 * 
 * @tparam  T Generic parameter
 * @param   [T] value - Value which has to be pushed onto the top of the stack
 */
template <typename T>
void
DS::Stack<T>::Push(T value)
{
    if(this->_Top == nullptr)
    {
        // Set the top of the stack if the top of the stack is empty
        this->_Top = new DS::Node<T>(value);
        // Increase the size of the stack by 1
        this->_Size++;
    }
    else if(this->_Capacity == 0 || this->_Size < this->_Capacity)
    {
        // Push the element to the top of the stack if space still exists
        DS::Node<T> *__TempNode = new DS::Node<T>(value);
        __TempNode->Next(this->_Top);
        this->_Top = __TempNode;
        // Increase the size of the stack by 1
        this->_Size++;
    }
    else
    {
        // If space does not exist on the stack, throw an exception
        throw Exception::AccessViolationException(
            "Stack is full. Cannot further push elements."
            );
    }
}

/**
 * @brief   Determines if the stack is empty or not
 * @details 
 * 
 * @tparam  T Generic parameter
 * @return  [bool] true if stack is empty else false
 */
template <typename T>
bool
DS::Stack<T>::IsEmpty()
{
    return this->_Top == nullptr;
}

/**
 * @brief   Returns the number of elements in the stack
 * @details
 *
 * @tparam  T Generic parameter
 * @return  [size_t] Number of elements in the stack
 */
template <typename T>
size_t
DS::Stack<T>::Size() const
{
    return this->_Size;
}

/**
 * @brief   Destructor for the stack
 * @details 
 * 
 * @tparam  T Generic parameter
 */
template <typename T>
DS::Stack<T>::~Stack()
{
    DS::Node<T> *__TempNode = this->_Top;
    // Pop out all the elements from the stack until the stack is empty
    while(__TempNode != nullptr)
    {
        this->Pop();
        // Reset the _Top pointer for continued pop
        __TempNode = this->_Top;
    }
    this->_Top = nullptr;
    this->_Capacity = 0;
}


