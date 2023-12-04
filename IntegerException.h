#pragma once

#include <exception>

using namespace std;

class IntegerException :
    public exception
{
private:
    const char* descException;
public:
    IntegerException(const char* descException) : descException(descException) {};
    virtual const char* what() const noexcept override { return descException; }
};

