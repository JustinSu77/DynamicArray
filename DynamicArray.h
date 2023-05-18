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
             *
             * @param value target value to search for
             * @return zero-based index of first occurrence of given value
             */
            int indexOf(T value);
            int length();
            int capacity();
            T at(int index);
            bool isFull();
            bool isEmpty();
            void operator=(const DynamicArray<T>& arr);
            bool operator==(const DynamicArray<T>& arr);
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

        array = new T[maxSize]{};

    }

    template<class T>
    DynamicArray<T>::DynamicArray( const std::initializer_list<T> &list): size(list.size()), maxSize(list.size())
    {

        array = new T[maxSize]{};
        int index = 0;
        for (auto element : list)
        {
            array[index] = element;
            index++;
        }


    }

    template<class T>
    DynamicArray<T>::DynamicArray(const DynamicArray<T> &arr): size(arr.size), maxSize(arr.maxSize)
    {

        array  = new T[maxSize]{};
        for (int i  = 0; i < size; i++)
        {
            array[i] = arr.array[i];
        }

    }

    template<class T>
    DynamicArray<T>::~DynamicArray()
    {
        delete[] array;
        array = nullptr;
    }

    template<class T>
    void DynamicArray<T>::print()
    {
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            if (i == size - 1)
                std::cout << array[i];
            else
                std::cout << array[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    template<class T>
    void DynamicArray<T>::sort()
    {
        if (size == 1 || isEmpty())
            return;
        for (int i = 0; i < size; i++)
        {
            bool isSwapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j+ 1])
                {
                    T temp = array[j];
                    array[j] =  array[j + 1];
                    array[j + 1] = temp;
                    isSwapped = true;
                }
            }
            if (!isSwapped)
                break;
        }


    }

    template<class T>
    void DynamicArray<T>::clear()
    {
        delete[] array;
        array = nullptr;
        array = new T[maxSize]{};
        size = 0;
    }

    template<class T>
    void DynamicArray<T>::resize(int newSize)
    {
        if (newSize <= 0 || newSize > INT_MAX)
            throw std::runtime_error("resize: Given newSize is out of bounds");
        if (isEmpty())
            return;
        int elements = newSize;
        if (newSize > size)
        {
            elements = size;
            maxSize = newSize;
        }
        T* newArray = new T[elements]{};
        for (int i = 0; i < elements; i++)
        {
            newArray[i] = array[i];
        }
        size = elements;
        delete [] array;
        array = nullptr;
        array = newArray;
    }

    template<class T>
    void DynamicArray<T>::fill(T newValue)
    {
        delete[] array;
        array = nullptr;
        array = new T[maxSize]{};
        for (int i = 0; i < maxSize; i++)
        {
            array[i] = newValue;
        }
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
        for (int i = 0; i < size; i++)
        {
            if (array[i] == value)
                return i;
        }
        return -1;
    }

    template<class T>
    T DynamicArray<T>::at(int index)
    {
        if (index < 0 || index > size - 1)
            throw std::runtime_error("at: Given index is out of bounds");
        return array[index - 1];
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
        delete[] array;
        array = nullptr;
        maxSize = arr.size;
        size = arr.size;
        array = new T[maxSize]{};
        for (int i = 0; i < size; i++)
        {
            array[i] = arr.array[i];
        }
    }

    template<class T>
    bool DynamicArray<T>::operator==(const DynamicArray<T> &arr)
    {
        if (size != arr.size || maxSize != arr.maxSize)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (array[i] != arr.array[i])
                return false;
        }
        return true;

    }



    template<class T>
    T &DynamicArray<T>::operator[](int position)
    {
        if( position < 0 || position > size - 1)
            throw std::runtime_error("[] operator: Given index out of bounds!");
        return array[position];
    }

    template<class T>
    DynamicArray<T>::DynamicArray(int maxSize): size(0), maxSize(maxSize)
    {
        array = new T[maxSize]{};
    }

    template<class T>
    void DynamicArray<T>::insertAtStart(T newValue)
    {
        if (isFull())
            doubleSize();
        for (int i = size; i >= 0; i--)
        {
            array[i + 1] = array[i];
        }
        array[0] = newValue;
        size++;

    }

    template<class T>
    void DynamicArray<T>::doubleSize()
    {
        T* newArray = new T[maxSize*2]{};
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        maxSize = maxSize * 2;
        delete[] array;
        array = newArray;
    }

    template<class T>
    void DynamicArray<T>::insertAtEnd(T newValue)
    {
        if (isFull())
            doubleSize();
        array[size] = newValue;
        size++;
    }

    template<class T>
    void DynamicArray<T>::insertAt(int index, T newValue)
    {
        if (index < 0 || index > size)
            throw std::runtime_error("insertAt: Given index is out of bounds");
        if (index == 0)
        {
            insertAtStart(newValue);
            return;
        }
        if (index == size - 1)
        {
            insertAtEnd(newValue);
            return;
        }
        if (isFull())
            doubleSize();
        for (int i = size; i >= index; i--)
        {
            array[i] = array[i + 1];
        }
        array[index] = newValue;
        size++;
    }

    template<class T>
    void DynamicArray<T>::insertSegment(int start, const std::initializer_list<T> &list)
    {
        if (isEmpty())
        {
            delete[] array;
            array = new T[list.size()]{};
            size = list.size();
            maxSize = list.size();
            int index = 0;
            for (auto element: list)
            {
                array[index] = element;
                index++;
            }
            return;
        }
        int newMaxSize = size + list.size();
        if (start < 0 || start > size)
            throw std::runtime_error("insertSegment: Given start index is out of bounds");
        if (newMaxSize > maxSize)
            doubleSize();
        size += list.size();
        T* newArray = new T[newMaxSize]{};
        int index  = start;
        typename std::initializer_list<T>::iterator iter = list.begin();
        for (int i = 0; i < size; i++)
        {
            if (i < start || i > start + list.size() - 1)
            {
                if (iter == list.end())
                {
                    newArray[i] = array[index];
                    index++;
                }
                else
                    newArray[i] = array[i];
            }
            else
            {
                newArray[i] = *iter;
                iter++;


            }
        }
        delete[] array;
        array = newArray;




    }

    template<class T>
    void DynamicArray<T>::removeAtStart()
    {
        if (isEmpty())
            throw std::runtime_error("removeAtStart: Array is empty!");
        for (int i = 0; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }

    template<class T>
    void DynamicArray<T>::removeAtEnd()
    {
        if (isEmpty())
            throw std::runtime_error("removeAtEnd: Array is empty!");
        T* newArray = new T[2]{};
        array[size - 1] = newArray[0];
        delete[] newArray;
        size--;
    }

    template<class T>
    void DynamicArray<T>::removeAt(int position)
    {
        if (position < 0 || position > size - 1)
            throw std::runtime_error("removeAt: Given index is out of bounds!");
        if (position == 0)
        {
            removeAtStart();
            return;
        }
        if (position == size - 1)
        {
            removeAtEnd();
            return;
        }
        for (int i = position; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;

    }

    template<class T>
    DynamicArray<T> DynamicArray<T>::getSegment(int start, int end)
    {
        if (isEmpty())
        {
            DynamicArray<int>arr;
            return arr;
        }

        if (start < 0 || end < 0)
            throw std::runtime_error("getSegment: start or end cannot be negative!");
        if (start >= end)
            throw std::runtime_error("getSegment: start index cannot be greater than end index!");
        if (end > size - 1)
            throw std::runtime_error("getSegment: Segment should be in bounds");
        int totalSize = end - start + 1;
        DynamicArray<T>arr(totalSize);
        int index = 0;
        for (int i = start; i <= end; i++)
        {
            arr.array[index] = array[i];
            index++;
        }
        arr.size = totalSize;
        return arr;
    }

    template<class T>
    void DynamicArray<T>::reverse()
    {
        int start = 0;
        int end = size - 1;
        while(start < end)
        {
            T temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }

    template<class T>
    void DynamicArray<T>::removeSegment(int start, int end)
    {
        if (isEmpty())
            throw std::runtime_error("Array is empty!");
        if (start < 0 || end < 0)
            throw std::runtime_error("getSegment: start or end cannot be negative!");
        if (start >= end)
            throw std::runtime_error("getSegment: start index cannot be greater than or equal to end index!");
        if (end > size - 1)
            throw std::runtime_error("getSegment: Segment should be in bounds");
        int newSize = end - start;
        std::cout << newSize << std::endl;
        T* newArray = new T[newSize]{};
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (i < start || i > end)
            {

                newArray[index] = array[i];
                index++;
            }
        }
        size = newSize;
        delete[] array;
        array = newArray;

    }



}
#endif
