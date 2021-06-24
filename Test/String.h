#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996) // ��������� ������������� Visual Studio �� ������������� strcpy
using namespace std;

class String
{
	char* _string;
	size_t _size;
public:
    explicit String(char* str)  //������� �����������
    {
        std::cout << "string constructed " << str << std::endl;
        _size = strlen(str) + 1;
        _string = new char[_size];
        strcpy(_string, str);
    }
    String(const String& other)     //����������� �����������
    {
        std::cout << "string copy constructed " << other._string << std::endl;
        _string = new char[other._size];
        strcpy(_string, other._string);
        _size = other._size;
    }
    String(String&& other)  noexcept    //���������� ����������� �����������
    {
        std::cout << "move constructor " << other._string << std::endl;
        _string = other._string;
        _size = other._size;
        other._string = nullptr;
        other._size = 0;
    }
    String& operator=(const String& other)
    {
        cout << "string copy constructed " << other._string << endl;
        _string = new char[other._size];
        strcpy(_string, other._string);
        _size = other._size;

        return *this;
    }
    String& operator=(String&& other) noexcept  //����������� ������������ �����������
    {
        cout << "move assignment constructor " << other._string << endl;
        _string = other._string;
        _size = other._size;
        other._string = nullptr;
        other._size = 0;

        return *this;
    }
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