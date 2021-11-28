/* Antonio Santana
* Hw07ProjectOOP.cpp : This file contains the 'main' function.
* 
* Reference: Source Code Organization (C++ Templates)
* https://docs.microsoft.com/en-us/cpp/cpp/source-code-organization-cpp-templates?view=msvc-170
*/ 


#include <iostream>
#include "List.h"

using namespace std;

template <class T>
void print(List<T> list)
{
    for (int i = 0; i < list.size(); i++)
        cout << list.get(i) << " ";
    cout << endl;
}

/// <summary>
/// Program execution begins and ends there.
/// </summary>
/// <returns></returns>
int main()
{
    const int SIZE = 10;

    // create list of integers and doubles
    List<int> intList(SIZE);
    List<double> doubleList(SIZE);

    // populate lists
    for (int i = 0; i < SIZE; i++) 
    {
        intList.add(i * 2);
        doubleList.add(i * 2.14);
    }

    //print lists
    cout << "integer list values: " << endl;
    print(intList);
    cout << "double list values: " << endl;
    print(doubleList);

    // populate again
    for (int i = 0; i < SIZE; i++) 
    {
        intList[i]++;
        doubleList[i]++;
    }

    //print lists 
    cout << "integer list values: " << endl;
    print(intList);
    cout << "double list values: " << endl;
    print(doubleList);

    return 0;
}