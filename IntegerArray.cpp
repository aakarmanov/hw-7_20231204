#include "IntegerArray.h"

IntegerArray::IntegerArray(int length) : m_length{ length } {
    if (length <= 0) throw  IntegerException("ОШИБКА! Не допустимый размер контейнера.");

    this->m_data = new int[length] {};
}

IntegerArray::~IntegerArray() {
    delete[] this->m_data;
}

void IntegerArray::erase() {
    delete[] this->m_data;
    this->m_data = nullptr;
    this->m_length = 0;
}

int& IntegerArray::operator[](int index) {
    if (index < 0 || index >= this->m_length) throw IntegerException("ОШИБКА! Выход за пределы контейнера");
    return this->m_data[index];
}

int IntegerArray::getLength() const { 
    return this->m_length; 
}

void IntegerArray::resize(int newLength) {
    if (newLength == this->m_length)
        return;

    if (newLength <= 0)
    {
        this->erase();
        return;
    }

    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
}

void IntegerArray::insertBefore(int value, int index) {
    
    if (index < 0 || index > this->m_length) throw IntegerException("ОШИБКА! Выход за пределы контейнера.");

    
    int* data{ new int[this->m_length + 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = this->m_data[before];

    data[index] = value;

    // Copy all of the values after the inserted element
    for (int after{ index }; after < this->m_length; ++after)
        data[after + 1] = this->m_data[after];

    delete[] this->m_data;
    this->m_data = data;
    ++this->m_length;
}

void IntegerArray::remove(int index) {    
    if (index < 0 || index >= this->m_length) throw IntegerException("ОШИБКА! Выход за пределы контейнера.");

    if (this->m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[this->m_length - 1] };
    
    for (int before{ 0 }; before < index; ++before)
        data[before] = this->m_data[before];
    
    for (int after{ index + 1 }; after < this->m_length; ++after)
        data[after - 1] = this->m_data[after];
    
    delete[] this->m_data;
    this->m_data = data;
    --this->m_length;
}

void IntegerArray::insertAtBeginning(int value) { this->insertBefore(value, 0); }

void IntegerArray::insertAtEnd(int value) { this->insertBefore(value, this->m_length); }

void IntegerArray::reallocate(int newLength)
{    
    this->erase();

    if (newLength <= 0)
        return;

    this->m_data = new int[newLength];
    this->m_length = newLength;
}

IntegerArray::IntegerArray(const IntegerArray& a) {    
    this->reallocate(a.getLength());
    
    for (int index{ 0 }; index < this->m_length; ++index)
        this->m_data[index] = a.m_data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a) {
    if (&a == this)
        return *this;

    this->reallocate(a.getLength());

    for (int index{ 0 }; index < this->m_length; ++index)
        this->m_data[index] = a.m_data[index];

    return *this;
}

int IntegerArray::find(int value) {    
    for (int i = 0; i < this->m_length; i++) {
        if (this->m_data[i] == value) return i;
    }
    return -1;
}