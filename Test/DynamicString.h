#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class DynamicString
{
private:
    size_t _size;
    char* _string;
public:
    DynamicString() = default;
    explicit DynamicString(const char* str);  //Базовый конструктор
    DynamicString(const DynamicString& other);     //конструктор копирования
    DynamicString(DynamicString&& other)  noexcept;    //Консруктор копирования перемещения
    DynamicString& operator=(const char* str);  //Оператор присваивания си-строки
    DynamicString& operator=(const DynamicString& other); //Оператор копирования пристваивания
    DynamicString& operator=(DynamicString&& other) noexcept;  //Оператор присваивания перемещения
    char& operator[](int index);     //Получение элемента по индексу
    const char* GetString() { return _string; }
    size_t GetSize() { return _size; }
    void SetSize(int size) { _size = size; }
    ~DynamicString() noexcept
    {
        delete[] _string;
    }
    friend ostream& operator<<(ostream& os, const DynamicString& str); //Оператор вывода строки
};

//Операторы сложения строк
DynamicString operator+(DynamicString str1, DynamicString str2);
DynamicString operator+(const char* str1, DynamicString str2);
DynamicString operator+(DynamicString str1, const char* str2);
//Функция лексикографического сравнения двух строк без учета регистра
bool cmp(DynamicString str1, DynamicString str2);
