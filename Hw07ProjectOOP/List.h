#pragma once
/* Antonio Santana
*  List.h : Specification file for the List class.
*
* Reference: Source Code Organization (C++ Templates)
* 
* The inclustion model: The simplest and most common way to make template 
* definitions visible throughout a translation unit, is to put the definitions 
* in the header file itself. Any .cpp file that uses the template simply has 
* to #include the header. This is the approach used in the Standard Library.
* 
* https://docs.microsoft.com/en-us/cpp/cpp/source-code-organization-cpp-templates?view=msvc-170
*/
#ifndef LIST
#define LIST

#include <cassert>

template <class T>
class List
{
public:
    // Constructor
    List(int cap)
    {
        // assign numElements and capacity (from obj) 
        numElements = 0;
        capacity = cap;

        // allocate memory based on capacity
        list = new T[cap];

        // assign all values to zero
        for (int i = 0; i < cap; i++)
            list[i] = 0;
    }

    // Destructor
    ~List()
    {
        // deallocate memory
        delete[] list;
    }

    // Copy constructor
    List(const List& obj)
    {
        // assign numElements and capacity (from obj) 
        numElements = obj.numElements;
        capacity = obj.capacity;

        // allocate memory based on capacity
        list = new T[capacity];

        // copy over elements (from obj)
        for (int i = 0; i < numElements; i++)
            list[i] = obj.list[i];
    }

    // Overloaded assignment operator
    List<T>& operator=(const List& obj)
    {
        if (this != &obj) // only assign if this != &obj
        {
            // delete list
            delete[] list;

            // assign numElements and capacity (from obj)
            numElements = obj.numElements;
            capacity = obj.capacity;

            // allocate memory based on capacity
            list = new int[capacity];

            // copy over elements (from obj)
            for (int i = 0; i < numElements; i++)
                list[i] = obj.list[i];
        }
        return *this;
    }

    // Overloaded [] operator
    T& operator[](const int& index)
    {
        assert(index >= 0 && index < capacity);
        return list[index];
    }

    // add element to array
    void add(T element)
    {
        // if the array is full, resize
        if (numElements >= capacity)
            resize();

        // the new element will be added whether
        // resize() is called or not!
        list[numElements] = element;
        numElements++;
    }

    // returns element at given index
    int get(int index) const
    {
        assert(index >= 0 && index < capacity);
        return list[index];
    }

    // returns number of elements in array
    int size()
    {
        // return the current number of elements in array
        return numElements;
    }

private:
	T* list;           // pointer to the array
	int capacity;        // capacity of array
	int numElements;     // number of elements in array

    // called to resize array when full
    void resize()
    {
        // update capacity
        capacity *= 2;

        // create new array based on updated capacity
        T* tempArr = new T[capacity];

        // copy old array values to new array
        int i = 0;
        for (; i < numElements; i++)
            tempArr[i] = list[i];
        for (; i < capacity; i++)
            tempArr[i] = 0;

        // delete old array
        delete[] list;

        // reassign old array to new array
        list = tempArr;
    }
};
#endif