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
    explicit DynamicString(const char* str);  //������� �����������
    DynamicString(const DynamicString& other);     //����������� �����������
    DynamicString(DynamicString&& other)  noexcept;    //���������� ����������� �����������
    DynamicString& operator=(const char* str);  //�������� ������������ ��-������
    DynamicString& operator=(const DynamicString& other); //�������� ����������� �������������
    DynamicString& operator=(DynamicString&& other) noexcept;  //�������� ������������ �����������
    char& operator[](int index);     //��������� �������� �� �������
    const char* GetString() { return _string; }
    size_t GetSize() { return _size; }
    void SetSize(int size) { _size = size; }
    ~DynamicString() noexcept
    {
        delete[] _string;
    }
    friend ostream& operator<<(ostream& os, const DynamicString& str); //�������� ������ ������
};

//��������� �������� �����
DynamicString operator+(DynamicString str1, DynamicString str2);
DynamicString operator+(const char* str1, DynamicString str2);
DynamicString operator+(DynamicString str1, const char* str2);
//������� ������������������� ��������� ���� ����� ��� ����� ��������
bool cmp(DynamicString str1, DynamicString str2);
