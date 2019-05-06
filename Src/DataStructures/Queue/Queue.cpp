/**
 *      Created on: 20 March 2018
 *   Last modified: 18 January 2019
 *          Author: sonapraneeth-a
 *         Details: Implementation of queue
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 20-03-2018               sonapraneeth-a      - Creation of the file
 * 24-03-2018               sonapraneeth-a      - Added implementations for queue 
 *                                                functions
 * 01-04-2018               sonapraneeth-a      - Fixed the Exceptions header path
 * 18-01-2019               sonapraneeth-a      - Renamed _MaxSize to _Capacity
 *                                              - Moved code to DS namespace
 *                                              - Added detailed comments for all
 *                                                functions
 */


/**
 * @brief   Empty constructor for queue
 * @details
 *
 * @tparam  T Generic Parameter
 */
template <typename T>
DS::Queue<T>::Queue()
{
    this->_Head = nullptr;  // _Head of the queue is null initially
    this->_Tail = nullptr;  // _Tail of the queue is null initially
    this->_Size = 0;        // _Size of the queue is also 0
    this->_Capacity = 0;    // If _Capacity is 0, then Queue has infinite capacity
}

/**
 * @brief   Constructor which fixes the maximum capacity queue can have
 * @details
 *
 * @tparam  T Generic parameter
 * @param   [T] value - Maximum size of the queue
 */
template <typename T>
DS::Queue<T>::Queue(T value)
{
    this->_Head = nullptr;      // _Head of the queue is null initially
    this->_Tail = nullptr;      // _Tail of the queue is null initially
    this->_Size = 0;            // _Size of the queue is also 0
    this->_Capacity = value;    // Maximum capacity of the queue is set to value
}

/**
 * @brief   Removes the element from the start of the queue and returns the value
 *          which was present at the start of the queue
 * @details If the queue is empty it throws an AccessViolationException
 *
 * @tparam  T Generic parameter
 * @return  [T] Value which was present at the start of the queue
 */
template <typename T>
T
DS::Queue<T>::Dequeue()
{
    if (this->_Head != nullptr && this->_Tail != nullptr)
    {
        // Get the pointer to the head node
        DS::Node<T> *__TempNode = this->_Head;
        // Update the head node to its next node
        this->_Head = this->_Head->Next();
        // Free the tail pointer if there is only one element in the queue
        if (this->_Size == 1)
        {
            this->_Tail = nullptr;
        }
        // Get the value present in the old head node which has been removed
        T value = __TempNode->Data();
        // Reduce the size of queue by 1
        this->_Size--;
        // Free up the space taken by old head node
        delete __TempNode;
        return value;
    }
    // Throw access violation exception for empty queues as dequeue on empty
    // queue is not possible
    throw Exception::AccessViolationException(
        "Queue is empty. Cannot further dequeue elements."
        );
}

/**
 * @brief   Adds an element to the end of the queue
 * @details
 *
 * @tparam  T Generic parameter
 * @param   [T] value - Value which has to be pushed to the end of the queue
 */
template <typename T>
void
DS::Queue<T>::Enqueue(T value)
{
    DS::Node<T> *__TempNode = new DS::Node<T>(value);
    // If both head and tail are null, then the queue is empty
    if(this->_Head == nullptr && this->_Tail == nullptr)
    {
        // Now set both the head and tail to the same node
        this->_Head = this->_Tail = __TempNode;
    }
    // Else update the tail pointer to point to the new node being inserted
    else
    {
        this->_Tail->Next(__TempNode);
        this->_Tail = __TempNode;
    }
    // Increase the size of the queue by 1
    this->_Size++;
}

/**
 * @brief   Determines if the queue is empty or not
 * @details
 *
 * @tparam  T Generic parameter
 * @return  [bool] true if queue is empty else false
 */
template <typename T>
bool
DS::Queue<T>::IsEmpty()
{
    return this->_Head == nullptr;
}

/**
 * @brief   Get the element at the start of the queue
 * @details If the queue is empty it throws an AccessViolationException
 *
 * @tparam  T Generic parameter
 * @return  [T] Value which is present at the start of the queue
 */
template <typename T>
T
DS::Queue<T>::HeadValue() const
{
    // If head pointer of queue is not null, then we can retrieve the value
    // in the head pointer
    if(this->_Head != nullptr)
    {
        return this->_Head->Data();
    }
    // If head pointer of te queue is null, then we cannot retrieve the value
    // in the head pointer
    throw Exception::AccessViolationException(
        "Queue is empty. Cannot retrieve elements from empty queue"
    );
}

/**
 * @brief   Get the element at the end of the queue
 * @details If the queue is empty it throws an AccessViolationException
 *
 * @tparam  T Generic parameter
 * @return  [T] Value which is present at the end of the queue
 */
template <typename T>
T
DS::Queue<T>::TailValue() const
{
    // If tail pointer of queue is not null, then we can retrieve the value
    // in the tail pointer (end of queue)
    if(this->_Tail != nullptr)
    {
        return this->_Tail->Data();
    }
    // If tail pointer of te queue is null, then we cannot retrieve the value
    // in the tail pointer (end of queue)
    throw Exception::AccessViolationException(
        "Queue is empty. Cannot retrieve elements from empty queue"
    );
}

/**
 * @brief   Returns the number of elements in the queue
 * @details
 *
 * @tparam  T Generic parameter
 * @return  [size_t] Number of elements in the queue
 */
template <typename T>
size_t
DS::Queue<T>::Size() const
{
    // Return the size of queue
    return this->_Size;
}

/**
 * @brief   Destructor for the queue
 * @details
 *
 * @tparam  T Generic parameter
 */
template <typename T>
DS::Queue<T>::~Queue()
{
    // Dequeue the queue until empty
    while(!this->IsEmpty())
    {
        this->Dequeue();
    }
    this->_Head = nullptr;
    this->_Tail = nullptr;
    this->_Size = 0;
    this->_Capacity = 0;
}

