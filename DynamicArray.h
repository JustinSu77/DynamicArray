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
            int index(int index);
            int length();
            int capacity();
            T at(int index);
            bool isFull();
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


}
#endif
