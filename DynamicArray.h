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
namespace justin_su
{
    template<class T>
    class DynamicArray
    {
        public:
            DynamicArray();
            DynamicArray(std::initializer_list<T>& list);
            DynamicArray(const DynamicArray<T>& arr);
            ~DynamicArray();
            void print();
            void sort();
            void clear();
            void resize(int newSize);
            void fill(T newValue);
            void insertAtStart(T newValue);
            void insertAtEnd(T newValue);
            void insertAt(int position, T newValue);
            void insertSegment(int start, std::initializer_list<T>& list);
            void removeAtStart();
            void removeAtEnd();
            void removeAt(int position, T newValue);
            void removeSegment(int start, int end);
            DynamicArray<T>getSegment(int start, int end);
            int indexOf(T value);
            int length();
            int capacity();
            T at(int index);
            bool isFull();
            bool isEmpty();
            void operator=(const DynamicArray<T>& arr);
            bool operator==(const DynamicArray<T>& arr);
            T& operator[](int position);
        private:
            T* array;
            int size;
            int maxSize;
            void doubleSize();
    };

    template<class T>
    DynamicArray<T>::DynamicArray(): size(0), maxSize(10)
    {
        delete[] array;
        array = new T[maxSize]{};

    }

    template<class T>
    DynamicArray<T>::DynamicArray(std::initializer_list<T> &list): size(list.size()), maxSize(list.size())
    {
        delete[] array;
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
        delete[] array;
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
    }

    template<class T>
    void DynamicArray<T>::print()
    {
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
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
                if (array[j + 1] > array[j])
                {
                    T temp = array[j + 1];
                    array[j + 1]= = array[j];
                    array[j] = temp;
                }
            }
        }


    }

    template<class T>
    void DynamicArray<T>::clear()
    {
        delete[] array;
        array = new T[maxSize]{};
        size = 0;
    }

    template<class T>
    void DynamicArray<T>::resize(int newSize)
    {
        if (newSize < 0 || newSize > INT_MAX)
            throw std::runtime_error("resize: Given newSize is out of bounds");
        if (isEmpty())
            return;
        maxSize = newSize;
        T* newArray = new T[maxSize]{};
        for (int i = 0; i < maxSize; i++)
        {
            newArray[i] = array[i];
        }
        delete [] array;
        array = newArray;



    }

    template<class T>
    void DynamicArray<T>::fill(T newValue)
    {
        delete[] array;
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
            std::runtime_error("at: Given index is out of bounds");
        return array[index - 1];
    }

    template<class T>
    bool DynamicArray<T>::isFull()
    {
        return size == maxSize;
    }


}
#endif
