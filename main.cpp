#include <iostream>
#include "DynamicArray.h"
using namespace justin_su;
int main()
{
    DynamicArray<int>arr;
    arr.insertSegment(2,{1,2,3,});
    arr.print();
    return 0;
}
