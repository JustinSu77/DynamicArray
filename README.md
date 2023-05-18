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