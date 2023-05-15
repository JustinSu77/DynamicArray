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
            DynamicArray(int maxSize);
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
    };

    template<class T>
    DynamicArray<T>::DynamicArray(): size(0), maxSize(1)
    {
        array = new T[maxSize]{};
        
    }


}
#endif
