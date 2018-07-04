/**
 *      Created on: 22 March 2018
 *   Last modified: 17 April 2018
 *          Author: Sona Praneeth Akula
 *         Details: Implementation for stack
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 22-03-2018             Sona Praneeth Akula   - Creation of the file
 *                                              - Added implementation of stack functions
 * 24-04-2018             Sona Praneeth Akula   - Fixed a problem with destructor
 *                                              - Updated condition for IsEmpty() function
 *                                              - Updated exception string for Pop()
 * 01-04-2018             Sona Praneeth Akula   - Fixed the Exceptions header path
 * 12-04-2018             Sona Praneeth Akula   - Added documentation for all the functions
 *                                              - Fixed the constructors to not add elements to top
 * 17-04-2018             Sona Praneeth Akula   - Added function to return size of the stack
 */


/**
 * @brief   Empty Stack constructor
 * @details 
 * 
 * @tparam T - Generic parameter
 */
template <typename T>
Stack<T>::Stack()
{
    this->Top = nullptr; // Top of the stack is null initially
    this->Size = 0;      // Size of the stack is also 0
    this->MaxSize = 0;   // If MaxSize is 0, then Stack has infinte capacity
}

/**
 * @brief   Constructor which fixes the maximum capacity it can have
 * @details 
 * 
 * @tparam T - Generic parameter
 * @param [T] - Value - Maximum size of the stack
 */
template <typename T>
Stack<T>::Stack(T Value)
{
    this->Top = nullptr;   // Top of the stack is null initially
    this->Size = 0;        // Size of the stack is also 0
    this->MaxSize = Value; // Sets the maximum size of the stack
}

/**
 * @brief   Get the element at the top of the stack
 * @details If the stack is empty it throws an EmptyException
 * 
 * @tparam T - Generic parameter
 * @return [T] - Value which is present at the top of the stack
 */
template <typename T>
T Stack<T>::Peek()
{
    if(this->Top != nullptr)
    {
        return this->Top->GetData();
    }
    throw EmptyException("Stack is empty. Cannot peek elements from empty stack");
}

/**
 * @brief   Removes the element from the top of the stack and returns the value which was present * *          at the top of the stack
 * @details If the stack is empty it throws an EmptyException
 * 
 * @tparam T - Generic parameter
 * @return [T] - Value which was present at the top of the stack
 */
template <typename T>
T Stack<T>::Pop()
{
    if (this->Top != nullptr)
    {
        // Get the pointer to the top of the stack
        StackNode<T> *TempNode = this->Top;
        // Get the value present in the top pointer
        T Value = TempNode->GetData();
        this->Top = this->Top->GetNext();
        // Free the memory for the top of the stack in order to remove the element
        delete TempNode;
        // Reduce the size of the stack by 1
        this->Size--;
        // Return the value which was present at the top of the stack to the
        // caller function
        return Value;
    }
    // Throw exception if the stack is empty
    throw EmptyException("Stack is empty. Cannot further pop elements.");
}

/**
 * @brief   Adds an element to the top of the stack
 * @details 
 * 
 * @tparam T - Generic parameter
 * @param [T] Value - Value which has to be pushed onto the top of the stack
 */
template <typename T>
void Stack<T>::Push(T Value)
{
    if(this->Top == nullptr)
    {
        // Set the top of the stack if the top of the stack is empty
        this->Top = new StackNode<T>(Value);
        // Increase the size of the stack by 1
        this->Size++;
    }
    else if(this->MaxSize == 0 || this->Size < this->MaxSize)
    {
        // Push the element to the top of the stack if space still exists
        StackNode<T> *TempNode = new StackNode<T>(Value);
        TempNode->SetNext(this->Top);
        this->Top = TempNode;
        // Increase the size of the stack by 1
        this->Size++;
    }
    else
    {
        // If space does not exist on the stack, throw an exception
        throw OverflowException("Stack is full. Cannot further push elements.");
    }
}

/**
 * @brief   Determines if the stack is empty or not
 * @details 
 * 
 * @tparam T - Generic parameter
 * @return [bool] - true if stack is empty else false
 */
template <typename T>
bool Stack<T>::IsEmpty()
{
    return this->Top == nullptr;
}

/**
 * @brief   Returns the number of elements in the stack
 * @details
 *
 * @tparam T - Generic parameter
 * @return [unsigned long long int] - Number of elements in the stack
 */
template <typename T>
ULLI Stack<T>::GetSize()
{
    return this->Size;
}

/**
 * @brief   Destructor for the stack
 * @details 
 * 
 * @tparam T - Generic parameter
 */
template <typename T>
Stack<T>::~Stack()
{
    StackNode<T> *TempNode = this->Top;
    while(TempNode != nullptr)
    {
        this->Pop();
        TempNode = this->Top;
    }
    this->MaxSize = 0;
}

