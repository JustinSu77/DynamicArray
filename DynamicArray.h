//DynamicArray();
//DynamicArray(int maxSize);
//DynamicArray(std::initializer_list<T>& list);
//DynamicArray(const DynamicArray<T>& arr);
//~DynamicArray();
//void print();
//void sort();
//void clear();
//void fill(T newValue);
//void insertAtStart(T newValue);
//void insertAtEnd(T newValue);
//void insertAt(int position, T newValue);
//void insertSegment(int start, std::initializer_list<T>& list);
//void removeAtStart();
//void removeAtEnd();
//void removeAt(int position, T newValue);
//void removeSegment(int start, int end);
//DynamicArray<T>getSegment(int start, int end);
//int index(int index);
//int length();
//int capacity();
//T at(int index);
//bool isFull();
//void operator=(const DynamicArray<T>& arr);
//bool operator==(const DynamicArray<T>& arr);
//T& operator[](int position);

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include <iostream>
#include <initializer_list>
#include <iterator>
namespace justin_su
{
    /**
     * Justin Su's implementation of a dynamic array class similar to a vector
     * @tparam T
     */
    template<class T>
    class DynamicArray
    {
        public:

            /**
            * Default constructor.
            * Sets size to 0
            * Sets maxSize to 10
            *  Sets array pointer to be a dynamic array with maxSize
            *
            */
            DynamicArray();

            /**
             * Creates a dynamic array with a maximum size of  maxSize.
             * Sets length to 0
             * Sets maxSize to given maxSize
             * Sets array pointer to dynamic array maximum size of maxSize
             * @param maxSize maxSize of array as int
             */
            DynamicArray(int maxSize);


            /**
             * Creates a dynamic array with elements from initializer_list.
             * Sets size to list.size
             * Sets maxSize to list.size
             * Copies elements from initializer_list to  array
             * @param list the elements array will have as an initializer list
             */
            DynamicArray(const std::initializer_list<T>& list);

            /**
             * Copy constructor.
             * Copies the size, maxSize, and elements from an existing instance of this class.
             * @param arr as an existing instance of this class
             */
            DynamicArray(const DynamicArray<T>& arr);

            /**
             * Destructor.
             * Deallocates the array pointer
             */
            ~DynamicArray();

            /**
             * Outputs the elements of array between square brackets.
             */
            void print();

            /**
             * Sorts array in ascending order
             * Uses optimized bubble sort
             * If array size is 0 or 1 returns
             * Precondition: Array has some elements
             * Postcondition: Array has some elements sorted in ascending order
             */
            void sort();

            /**
             * Reverses the order of the elements in the array
             * If array size is 0 or 1 return
             * Precondition: Array has some elements
             * Postcondition: Array elements has been reversed
             */
            void reverse();

            /**
             * Clear elements from array.
             * Sets size to 0
             * Reallocate array pointer to dynamic array with maxSize maximum size
             * Sets elements to default templated value
             * Precondition: Array has some elements
             * Postcondition: Array size is set to 0
             *                Elements are set to default template value
             */
            void clear();

            /**
             * Resize the array.
             * Allocates array with new size based on given newSize
             * Precondition: Array has some elements
             * Postcondition:  If given newSize is <= 0, throw runtime_error
             *                 If given newSize is INT_MAX, throw runtime_error
             *                  If given newSize is less than current size, copies element up to current size
             *                      and sets maxSize to size
             *                  Otherwise reallocates array with given maximum size of newSize
             *                      and copies all elements from old array to new array
             * @param newSize
             */
            void resize(int newSize);

            /**
             * Fill array with given newValue up to capacity.
             * Reallocates array pointer and sets all elements to default templated value
             * Sets all elements to given newValue
             * Precondition: Array has some elements
             * @param newValue as value array is filled with as templated value
             */
            void fill(T newValue);
            /**
             * Inserts given newValue to beginning of array.
             * If array is full, creates new array with double the capacity,
             *  and copies the elements from old array to new array
             *  Precondition: Array has some elements or it is empty
             *  Postcondition: Given new value is not inserted at the beginning of the array
             *                 Size is increased by 1
             *                 If array was full prior to insertion, double the capacity of the array
             *                  and insert the given newValue
             * @param newValue as value to be inserted at start as templated value
             */
            void insertAtStart(T newValue);


            /**
             * Inserts given newValue at end of array.
             * Precondition: Array has some elements or is empty.
             * Postcondition: Given value is inserted at end of array.
             *                 Size is increased by 1
             *                 If array was full prior to insertion
             *                   double the capacity of array
             * @param newValue
             */
            void insertAtEnd(T newValue);

            /**
             * Insert given newValue at given zero-based index.
             * If index is < 0 or index > size - 1, throw runtime_error
             * Precondition: Array is empty or has some elements
             * Postcondition: If given index is 0, call insertAtStart()
             *                If given index is size - 1, call insertAtEnd()
             *                Otherwise shift elements to right and insert newValue at given index
             *                Increase size by 1
             * @param index as zero-based index to insert newValue
             * @param newValue as the new value to be inserted in to the array.
             */
            void insertAt(int index, T newValue);

            /**
             * Insert a given list of elements at the given start index
             * Precondition: Array is empty or has some elements already.
             * Postcondtion:
             *               If array is empty, just add the list elements to array and set size
             *                  and maxSize to list.size()
             *               If the given start index is < 0 or greater than size, throw runtime_error
             *               If array is full prior to inserting new elements, double its capacity
             *               The elements of the initializer_list is added starting at the given start index
             *               Size is increased by list.size()
             * @param start the zero-based index to insert the elements at as int
             * @param list list of elements to insert int array
             */
            void insertSegment(int start, const std::initializer_list<T>& list);

            /**
             * Removes the first element of the array.
             * Precondition: Array is empty or has some elements
             * Postcondition: If array is already empty, throw runtime_error
             *                Remove the last element of the array
             *                Decrease size by 1
             */
            void removeAtStart();

            /**
             * Remove the last element of array.
             * Precondition: Array is empty or has some elements
             * Postcondition: If array is already empty, throw runtime_error
             *                Last element of array is removed
             *                Size is decreased by 1
             *
             */
            void removeAtEnd();

            /**
             * Removes the element at the given zero-based position.
             *  Precondition: Array is empty or has some elements
             *  Postconditon: If array is empty, throw runtime_error
             *                If position < 0 or position is > size - 1, throw runtime_error
             *                Otherwise element at position is removed
             *                Size is decreased by 1
             * @param position zero-based index of array to remove element from
             */
            void removeAt(int position);

            /**
             * Remove a segment of elements from the array.
             * Precondition: Array is empty or has some elements.
             * Postcondition: Array is empty, throw runtime-error
             *                If start or end is negative, throw runtime_error
             *                If start >= end, throw runtime_error
             *                if end > size - 1, throw runtime error
             *                Otherwise remove the segment from array
             *                Decrease size by number of elements in list
             * @param start as zero-based index of beginning of segment to remove
             * @param end as zero-based index of end of segment to remove
             */
            void removeSegment(int start, int end);

            /**
             * Returns a segment of the array as an instance of this class.
             * Precondition: Array is empty or has some elements
             * Postcondition: If array is empty, throw runtime_error
             *                If given start index is < 0 or given end index is < 0
             *                  throw runtime_error
             *                If given start index >= end, throw runtime_error
             *                If given end is greater than size - 1, throw runtime_error
             *                Otherwise return a instance of this clas
             * @param start zero-based index where segment starts
             * @param end zero-based index where segment ends
             * @return
             */
            DynamicArray<T>getSegment(int start, int end);

            /**
             * Returns the index of the first occurrence of the value.
             * Preconditon: Array has some elements or is empty
             * Postconditon: The zero-based index of the first occurrence of the given value is returned
             *               Or -1 is returned if value does not exist
             * @param value target value to search for
             * @return zero-based index of first occurrence of given value
             */
            int indexOf(T value);

            /**
             * Returns the size of the array.
             * @return size of array as int
             */
            int length();

            /**
             * Return the max size of the array
             @return max size of the array as int
             */
            int capacity();

            /**
             * Return the value at the given zero-based index.
               If the index < 0 or index > size - 1 throw runtime_error
               @param index as zero-based index of the element to be returned
               @return
             */
            T at(int index);

            /**
             * Return whether or not array is full.
             * Array is full if size == maxSize
             * @return true if size == maxSize, false otherwise
             */
            bool isFull();

            /**
             * Return whether or not array is empty.
             *  Array is empty if size == 0
             * @return true if size == 0, false otherwise
             */
            bool isEmpty();

            /**
             * Sets the size, maxSize, and elements of this class equal to an existing instance of this class.
               @param arr as an existing instance of this class
             */
            void operator=(const DynamicArray<T>& arr);

            /**
             * Return whether or not two instances of this class are equal to each other.
             * size, maxSize, and elements need to be the same
             * @param arr as an existing instance of this class
             * @return
             */
            bool operator==(const DynamicArray<T>& arr);

            /**
             * Bracket operator overload.
             *  Returns the element at the given zero-based index
             *  If the given index is < 0 or > size - 1, throw runtime_error
             *
             * @param index as zero-based index the elemenet is to be returned from
             * @return
             */
            T& operator[](int index);
        private:
            T* array;
            int size;
            int maxSize;
            void doubleSize();
    };


    template<class T>
    DynamicArray<T>::DynamicArray(): size(0), maxSize(10)
    {
        // Allocate array pointer to dynamic array
        array = new T[maxSize]{};

    }

    template<class T>
    DynamicArray<T>::DynamicArray( const std::initializer_list<T> &list): size(list.size()), maxSize(list.size())
    {

        // Allocate array pointer to dynamic array
        array = new T[maxSize]{};
        // Used to copy elements from initializer list
        int index = 0;
        // Copy elements from initializer list to array
        for (auto element : list)
        {
            // Set value from list to index
            array[index] = element;
            // Increment index
            index++;
        }


    }

    template<class T>
    DynamicArray<T>::DynamicArray(const DynamicArray<T> &arr): size(arr.size), maxSize(arr.maxSize)
    {

        // Allocate array pointer to dynamic array
        array  = new T[maxSize]{};
        // Copy the elements from other instance's array to this arrayy
        for (int i  = 0; i < size; i++)
        {
            array[i] = arr.array[i];
        }

    }

    template<class T>
    DynamicArray<T>::~DynamicArray()
    {
        // Deallocate array
        delete[] array;
        // Set array to nullptr
        array = nullptr;
    }

    template<class T>
    DynamicArray<T>::DynamicArray(int maxSize): size(0), maxSize(maxSize)
    {

        array = new T[maxSize]{};
    }

    template<class T>
    void DynamicArray<T>::print()
    {
        // Print first bracket
        std::cout << "[";
        // Print elements
        for (int i = 0; i < size; i++)
        {
            // If the last element is printed, dont print space
            if (i == size - 1)
                std::cout << array[i];
            // Print space between elements
            else
                std::cout << array[i] << " ";
        }
        // Print bracket
        std::cout << "]" << std::endl;
    }

    template<class T>
    void DynamicArray<T>::sort()
    {
        // If there is only 1 element or array is empty return
        if (size == 1 || isEmpty())
            return;
        // Optimized bubble sort
        for (int i = 0; i < size; i++)
        {
            // Flag to stop early
            bool isSwapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                // If current element is greater than
                if (array[j] > array[j+ 1])
                {
                    // Swap elements
                    T temp = array[j];
                    array[j] =  array[j + 1];
                    array[j + 1] = temp;
                    // Set flag to true
                    isSwapped = true;
                }
            }
            // if no swap happened end loop early
            if (!isSwapped)
                break;
        }


    }

    template<class T>
    void DynamicArray<T>::clear()
    {
        // Deallocate array
        delete[] array;
        // Sets array to nullpointer
        array = nullptr;
        // Reallocate array and fill with default values
        array = new T[maxSize]{};
        // Set size to 0
        size = 0;
    }

    template<class T>
    void DynamicArray<T>::resize(int newSize)
    {
        // If newsize is negative or 0 or is greater than INT_MAX
        if (newSize <= 0 || newSize > INT_MAX)
            throw std::runtime_error("resize: Given newSize is out of bounds");
        // Set number of elements to given maxSize
        int elements = newSize;
        // Sets max size to given newSize
        maxSize = newSize;
        // If array will be made shorter
        if (newSize < size)
            // Set elements to be in array to size
            elements = size;
        // Create new array set to default values
        T* newArray = new T[elements]{};
        // Copy the elements from old array to new array
        for (int i = 0; i < elements; i++)
        {
            newArray[i] = array[i];
        }
        // Set size to newSize
        size = newSize;
        // Deallocate array pointer
        delete [] array;
        array = nullptr;
        // Set array to point to new array;
        array = newArray;
    }

    template<class T>
    void DynamicArray<T>::fill(T newValue)
    {
        // Create new array and set all elements of array to default values
        delete[] array;
        array = nullptr;
        array = new T[maxSize]{};
        // Fill array with  given newValue
        for (int i = 0; i < maxSize; i++)
        {
            array[i] = newValue;
        }
        // Set array to be full
        size = maxSize;

    }

    template<class T>
    int DynamicArray<T>::length()
    {
        return size;
    }

    template<class T>
    int DynamicArray<T>::capacity()
    {
        return maxSize;
    }


    template<class T>
    int DynamicArray<T>::indexOf(T value)
    {
        // Linear search
        for (int i = 0; i < size; i++)
        {
            // when value is found return its index
            if (array[i] == value)
                return i;
        }
        // If value does not exist return -1
        return -1;
    }

    template<class T>
    T DynamicArray<T>::at(int index)
    {
        // If given index is out of bounds
        if (index < 0 || index > size - 1)
            throw std::runtime_error("at: Given index is out of bounds");
        return array[index];
    }

    template<class T>
    bool DynamicArray<T>::isFull()
    {
        return size == maxSize;
    }

    template<class T>
    bool DynamicArray<T>::isEmpty()
    {
        return size == 0;
    }

    template <class T>
    void DynamicArray<T>::operator=(const DynamicArray<T> &arr)
    {
        // delete array
        delete[] array;
        array = nullptr;
        // Copy size and maxSize
        maxSize = arr.size;
        size = arr.size;
        // Reallocate array to new dynamic array
        array = new T[maxSize]{};
        // Copy elements from array of given instance to new array
        for (int i = 0; i < size; i++)
        {
            array[i] = arr.array[i];
        }
    }

    template<class T>
    bool DynamicArray<T>::operator==(const DynamicArray<T> &arr)
    {
        // If the size and maxSize are different return false
        if (size != arr.size || maxSize != arr.maxSize)
            return false;
        // Loop through all elements
        for (int i = 0; i < size; i++)
        {
            // if any element is different return false
            if (array[i] != arr.array[i])
                return false;
        }
        // Otherwise
        return true;

    }



    template<class T>
    T &DynamicArray<T>::operator[](int position)
    {
        // If given position is out of bounds, throw runtime_error
        if( position < 0 || position > size - 1)
            throw std::runtime_error("[] operator: Given index out of bounds!");
        // Otherwise return element at given position
        return array[position];
    }



    template<class T>
    void DynamicArray<T>::insertAtStart(T newValue)
    {
        // If array is full, double its capacity
        if (isFull())
            doubleSize();
        // Shift elements to the right
        for (int i = size; i >= 0; i--)
        {
            array[i + 1] = array[i];
        }
        // Set first element to newValue
        array[0] = newValue;
        // Increase size by 1
        size++;

    }

    template<class T>
    void DynamicArray<T>::doubleSize()
    {
        // Create new array that is double the capacity of current array
        // Set to default value
        T* newArray = new T[maxSize*2]{};
        // Copy the elements from old array to new array
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        // Double maxSize
        maxSize = maxSize * 2;
        // Deallocate array
        delete[] array;
        array = nullptr;
        // Set array to new array
        array = newArray;
    }

    template<class T>
    void DynamicArray<T>::insertAtEnd(T newValue)
    {
        // If array is full double its capacity
        if (isFull())
            doubleSize();
        // Set last element to be given value
        array[size] = newValue;
        // Increase size by 1
        size++;
    }

    template<class T>
    void DynamicArray<T>::insertAt(int index, T newValue)
    {
        // If index is out of bounds, throw exception
        if (index < 0 || index > size)
            throw std::runtime_error("insertAt: Given index is out of bounds");
        // If index is 0, call insertAtStart
        if (index == 0)
        {
            insertAtStart(newValue);
            return;
        }
        //if index is size - 1, throw exception
        if (index == size - 1)
        {
            insertAtEnd(newValue);
            return;
        }

        // If array is full double its size
        if (isFull())
            doubleSize();
        // Shift elements starting at given index to the right
        for (int i = size; i >= index; i--)
        {
            array[i] = array[i + 1];
        }
        // Set given newValue to
        array[index] = newValue;
        // Increase size by 1
        size++;
    }

    template<class T>
    void DynamicArray<T>::insertSegment(int start, const std::initializer_list<T> &list)
    {
        // If array is empty, just insert the elements into array
        if (isEmpty())
        {
            // Deallocate array
            delete[] array;
            array = nullptr;
            // Reallocate array
            array = new T[list.size()]{};
            // Set size to list.size
            size = list.size();
            // Set maxSize to list.size
            maxSize = list.size();
            // Index of array
            int index = 0;
            // Copy elements from initializer list to array
            for (auto element: list)
            {
                array[index] = element;
                // Increment index by 1
                index++;
            }
            // Get out of function
            return;
        }
        // New size of array
        int newMaxSize = size + list.size();
        // If given start index is out of bounds, throw exception
        if (start < 0 || start > size)
            throw std::runtime_error("insertSegment: Given start index is out of bounds");
        // If array is full, double the array
        if (newMaxSize > maxSize)
            doubleSize();
        // Add number of elements added to size
        size += list.size();
        // Create new array
        T* newArray = new T[newMaxSize]{};
        // index where the segment is inserted
        int index  = start;
        // iterator to get element from initializer list
        typename std::initializer_list<T>::iterator iter = list.begin();

        // Traverse the array
        for (int i = 0; i < size; i++)
        {
            // If the current index traversed is not in the range where new segment is inserted
            if (i < start || i > start + list.size() - 1)
            {
                // If elements from initializer list has been copied, copy the rest other elements from the old array
                //  to new array
                // For situations where the inserted segment is between existing elements
                if (iter == list.end())
                {
                    // Copy element
                    newArray[i] = array[index];
                    // Increase the index
                    index++;
                }
                // Copy elements from old array to new array
                else
                    newArray[i] = array[i];
            }
            // Copy elements from initializer list to newArray
            else
            {
                newArray[i] = *iter;
                iter++;
            }
        }
        // Deallocate array
        delete[] array;
        array = nullptr;
        // Set array to newArray
        array = newArray;




    }

    template<class T>
    void DynamicArray<T>::removeAtStart()
    {
        // If array is already emtpy, throw exception
        if (isEmpty())
            throw std::runtime_error("removeAtStart: Array is empty!");
        // Shift element to left
        for (int i = 0; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        // Decrease size by 1
        size--;
    }

    template<class T>
    void DynamicArray<T>::removeAtEnd()
    {
        // If array is already emtpy, throw exception
        if (isEmpty())
            throw std::runtime_error("removeAtEnd: Array is empty!");
        // Create temp array to get default value of data type T
        T* newArray = new T[2]{};
        // Set last element to be the default value of T
        array[size - 1] = newArray[0];
        // Deallocate array
        delete[] newArray;
        // Decrease size by 1
        size--;
    }

    template<class T>
    void DynamicArray<T>::removeAt(int position)

    {  // If given position is out of bounds, throw exception
        if (position < 0 || position > size - 1)
            throw std::runtime_error("removeAt: Given index is out of bounds!");
        // If given position is 0, call removeAtStart function
        if (position == 0)
        {
            removeAtStart();
            // Get out of function once done
            return;
        }
        // If given position is the last element, call removeAtEnd function
        if (position == size - 1)
        {
            removeAtEnd();
            // Get out of functions once done
            return;
        }
        // Shift elements to left starting at given position
        for (int i = position; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        // Decrease size by 1
        size--;

    }

    template<class T>
    DynamicArray<T> DynamicArray<T>::getSegment(int start, int end)
    {
        // If array is empty, return a default instance of this class
        if (isEmpty())
        {
            DynamicArray<int>arr;
            return arr;
        }
        // if given start or end are negative, throw exception
        if (start < 0 || end < 0)
            throw std::runtime_error("getSegment: start or end cannot be negative!");
        // If start index is greater or equal to end, throw exception
        if (start >= end)
            throw std::runtime_error("getSegment: start index cannot be greater than end index!");
        // If given end is out of bounds, throw exception
        if (end > size - 1)
            throw std::runtime_error("getSegment: Segment should be in bounds");
        // Total number of elements returned instance will have
        int totalSize = end - start + 1;
        // Create instance of this class
        DynamicArray<T>arr(totalSize);
        // Copying elements start at 0
        int index = 0;
        // Copy segment of array into array of instance of this class
        for (int i = start; i <= end; i++)
        {
            arr.array[index] = array[i];
            index++;
        }
        // Set the size of the returned instance
        arr.size = totalSize;
        // Return the instance
        return arr;
    }

    template<class T>
    void DynamicArray<T>::reverse()
    {
        // Set pointer to beginning of array
        int start = 0;
        // Set pointer to end of array
        int end = size - 1;
        // While pointers are not crossing
        while(start < end)
        {
            // Swap elements
            T temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            // Increment start counter
            start++;
            // Decrement end counter
            end--;
        }
    }

    template<class T>
    void DynamicArray<T>::removeSegment(int start, int end)
    {
        // If array is empty, throw exception
        if (isEmpty())
            throw std::runtime_error("Array is empty!");
        // If given start or end is negative, throw exception
        if (start < 0 || end < 0)
            throw std::runtime_error("getSegment: start or end cannot be negative!");
        // If start index is greater than end, throw exception
        if (start >= end)
            throw std::runtime_error("getSegment: start index cannot be greater than or equal to end index!");
        // If end is out of bounds, throw exception
        if (end > size - 1)
            throw std::runtime_error("getSegment: Segment should be in bounds");
        // new size of array after elements are removed
        int newSize = end - start;
        // Allocate new array with default values
        T* newArray = new T[newSize]{};
        // counter to copy elements starting at 0
        int index = 0;
        // Loop through elements
        for (int i = 0; i < size; i++)
        {
            // If index is in range of segment of array to remove
            if (i < start || i > end)
            {
                // Copy those elements
                newArray[index] = array[i];
                index++;
            }
        }
        // Set size of to newSize
        size = index;
        // Deallocate old array
        delete[] array;
        array = nullptr;
        // Set array to newArray
        array = newArray;

    }



}
#endif
