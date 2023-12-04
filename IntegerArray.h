#pragma once
#include "IntegerException.h"

class IntegerArray
{
private:
    int m_length{};
    int* m_data{};
public:
    IntegerArray() = default;
    IntegerArray(int length);
    IntegerArray(const IntegerArray& a);
    ~IntegerArray();
    
    void erase();
    int& operator[](int index);
    int getLength() const;
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    IntegerArray& operator=(const IntegerArray& a);
    int find(int value);
};

