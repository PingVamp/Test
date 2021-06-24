#pragma once
#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable : 4996) // отключаем предупрждени€ Visual Studio об использовании strcpy
using namespace std;

class String
{
	char* _string;
	size_t _size;
public:
    explicit String(const char* str)  //Ѕазовый конструктор
    {
        //std::cout << "string constructed " << str << std::endl;
        _size = strlen(str) + 1;
        _string = new char[_size];
        strcpy_s(_string, _size, str);
    }
    String(const String& other)     //конструктор копировани€
    {
        //std::cout << "string copy constructed " << other._string << std::endl;
        _size = other._size;
        _string = new char[_size];
        strcpy_s(_string, _size, other._string);
    }
    String(String&& other)  noexcept    // онсруктор копировани€ перемещени€
    {
        //std::cout << "move constructor " << other._string << std::endl;
        _string = other._string;
        _size = other._size;
        other._string = nullptr;
        other._size = 0;
    }
    String& operator=(const String& other) //ќператор копировани€ пристваивани€
    {
        //cout << "string copy constructed " << other._string << endl;
        _string = new char[other._size];
        strcpy_s(_string, _size, other._string);
        _size = other._size;

        return *this;
    }
    String& operator=(String&& other) noexcept  //ќператор присваивани€ перемещени€
    {
        //cout << "move assignment constructor " << other._string << endl;
        _string = other._string;
        _size = other._size;
        other._string = nullptr;
        other._size = 0;

        return *this;
    }
    char& operator[](int index)
    {
        if (index < 0 || index > _size)
        {
            cout << "Bad Index" << endl;
        }
        else
        {
            return _string[index];
        }
    }
    const char* GetString() { return _string; }
    size_t GetSize() { return _size; }
    ~String() noexcept
    {
        delete[] _string;
    }
    friend ostream& operator<<(ostream& os, const String& str);
};

ostream& operator<<(ostream& os, const String& str)
{
    os << str._string;
    return os;
}

String operator+(String str1, String str2)
{
    char* sum = new char[str1.GetSize() + str2.GetSize()];
    strcpy(sum, str1.GetString());
    strcat(sum, str2.GetString());
    return String(sum);
}
String operator+(const char* str1, String str2)
{
    char* sum = new char[strlen(str1) + str2.GetSize()];
    strcpy(sum, str1);
    strcat(sum, str2.GetString());
    return String(sum);
}
String operator+(String str1, const char* str2)
{
    char* sum = new char[str1.GetSize() + strlen(str2)];
    strcpy(sum, str1.GetString());
    strcat(sum, str2);
    return String(sum);
}