#include <iostream>
#include "IntegerArray.h"
#include "IntegerException.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, ""); // или system("chcp 1251"); 
        
    //Ошибки при создании контейнера
    try {
        cout << "Создание контейнера: integerArray1(-1); ";
        IntegerArray integerArray1(-1);
    }
    catch (IntegerException& e) {
        cout << e.what() << endl;
    }
        
    //Ошибки доступа 
    try {
        IntegerArray integerArray2(10);        
        cout << "Размер контейнера integerArray2: " << integerArray2.getLength() << endl;
        for (int i = 0; i < 10; i++)integerArray2[i] = i;
        cout << "Распечатка контейнера: ";
        for (int i = 0; i < 11; i++) cout << integerArray2[i] << " ";
    }
    catch (IntegerException& e) {
        cout << e.what() << endl;
    }

    //Изменение размера контейнера
    try {
        IntegerArray integerArray3(5);
        cout << "Размер контейнера integerArray3: " << integerArray3.getLength() << endl;
        integerArray3.resize(10);
        cout << "Изменение размера контейнера integerArray3, новый размер: " << integerArray3.getLength() << endl;
        
    }
    catch (IntegerException& e) {
        cout << e.what() << endl;
    }

    //Добавление / удаление элементов массива
    try {
        IntegerArray integerArray4(10);        
        for (int i = 0; i < integerArray4.getLength(); i++)integerArray4[i] = i;
        cout << "Контейнер integerArray4: ";
        for (int i = 0; i < integerArray4.getLength(); i++) cout << integerArray4[i] << " ";
        cout << endl;
        cout << "Вставляем новый элемент (integerArray4.insertBefore(11,5);): ";
        integerArray4.insertBefore(11,5);
        for (int i = 0; i < integerArray4.getLength(); i++) cout << integerArray4[i] << " ";
        cout << endl;
        
        //Копирование
        cout << "Копирование контейнера integerArray4 в integerArray5: ";
        IntegerArray integerArray5;        
        integerArray5 = integerArray4;
        for (int i = 0; i < integerArray5.getLength(); i++) cout << integerArray5[i] << " ";
        cout << endl;
        
        //Удаление элемента
        cout << "Удаление первого и последнего элементов: "; 
        integerArray4.remove(integerArray4.getLength()-1);
        integerArray4.remove(0);
        for (int i = 0; i < integerArray4.getLength(); i++) cout << integerArray4[i] << " ";
        cout << endl;

        //Добавление элемента в начало и конец: 
        cout << "Добавление элемента в начало и конец: ";
        integerArray4.insertAtBeginning(8);
        integerArray4.insertAtEnd(8);
        for (int i = 0; i < integerArray4.getLength(); i++) cout << integerArray4[i] << " ";
        cout << endl;

        //Ошибка вставки элемента
        cout << "Вставляем новый элемент (integerArray4.insertBefore(22, 12);): ";
        integerArray4.insertBefore(22, 12);
        for (int i = 0; i < integerArray4.getLength(); i++) cout << integerArray4[i] << " ";
        cout << endl;
    }
    catch (IntegerException& e) {
        cout << e.what() << endl;
    }

    //Поиск элемента в контейнере
    try {
        IntegerArray integerArray6(10);        
        for (int i = 0; i < 10; i++)integerArray6[i] = i;
        cout << "Контейнер integerArray6: ";
        for (int i = 0; i < integerArray6.getLength(); i++) cout << integerArray6[i] << " ";
        cout << endl;
        cout << "Поиск значения 8 в контейнере: " << integerArray6.find(8) << endl;
        cout << "Поиск значения 11 в контейнере: " << integerArray6.find(11) << endl;
    }
    catch (IntegerException& e) {
        cout << e.what() << endl;
    }

    
}
