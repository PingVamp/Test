#include "DynamicString.h"

DynamicString::DynamicString(const char* str)
{
	_size = strlen(str) + 1;
	_string = new char[_size];
	strcpy_s(_string, _size, str);
}

DynamicString::DynamicString(const DynamicString& other)
{
	_size = other._size;
	_string = new char[_size];
	strcpy_s(_string, _size, other._string);
}

DynamicString::DynamicString(DynamicString&& other) noexcept
{
	_string = other._string;
	_size = other._size;
	other._string = nullptr;
	other._size = 0;
}

DynamicString& DynamicString::operator=(const char* str)
{
	_size = strlen(str) + 1;
	_string = new char[_size];
	strcpy_s(_string, _size, str);
}

DynamicString& DynamicString::operator=(const DynamicString& other)
{
	_string = new char[other._size];
	strcpy_s(_string, _size, other._string);
	_size = other._size;

	return *this;
}

DynamicString& DynamicString::operator=(DynamicString&& other) noexcept
{
	_string = other._string;
	_size = other._size;
	other._string = nullptr;
	other._size = 0;

	return *this;
}

char& DynamicString::operator[](int index)
{
	return _string[index];
}

ostream& operator<<(ostream& os, const DynamicString& str)
{
	os << str._string;
	return os;
}

DynamicString operator+(DynamicString str1, DynamicString str2)
{
	char* sum = new char[str1.GetSize() + str2.GetSize()];
	strcpy_s(sum, strlen(sum), str1.GetString());
	strcat_s(sum, strlen(sum), str2.GetString());
	DynamicString str(sum);
	delete[] sum;
	return str;
}

DynamicString operator+(const char* str1, DynamicString str2)
{
	char* sum = new char[strlen(str1) + str2.GetSize()];
	strcpy_s(sum, strlen(sum), str1);
	strcat_s(sum, strlen(sum), str2.GetString());
	DynamicString str(sum);
	delete[] sum;
	return str;
}

DynamicString operator+(DynamicString str1, const char* str2)
{
	char* sum = new char[str1.GetSize() + strlen(str2)];
	strcpy_s(sum, strlen(sum), str1.GetString());
	strcat_s(sum, strlen(sum), str2);
	DynamicString str(sum);
	delete[] sum;
	return str;
}

bool cmp(DynamicString str1, DynamicString str2)    //Функция лексикографического сравнения двух строк без учета регистра
{
    char* tmp_str1 = new char[str1.GetSize() + 1];
    char* tmp_str2 = new char[str2.GetSize() + 1];
    bool isless = false;
    char* add = new char[2];
    if (str1[0] >= 65 && str1[0] <= 90)
    {
        add[0] = str1[0] + 32;
        add[1] = '\0';
        strcpy_s(tmp_str1, strlen(tmp_str1), add);
    }
    else
    {
        add[0] = str1[0];
        add[1] = '\0';
        strcpy_s(tmp_str1, strlen(tmp_str1), add);
    }
    for (size_t i = 1; i < str1.GetSize(); i++)
    {
        if (str1[i] >= 65 && str1[i] <= 90)
        {
            add[0] = str1[i] + 32;
            add[1] = '\0';
            strcat_s(tmp_str1, strlen(tmp_str1), add);
        }
        else
        {
            add[0] = str1[i];
            add[1] = '\0';
            strcat_s(tmp_str1, strlen(tmp_str1), add);
        }
    }
    if (str2[0] >= 65 && str2[0] <= 90)
    {
        add[0] = str1[0] + 32;
        add[1] = '\0';
        strcpy_s(tmp_str2, strlen(tmp_str2), add);
    }
    else
    {
        add[0] = str2[0];
        add[1] = '\0';
        strcpy_s(tmp_str2, strlen(tmp_str2), add);
    }
    for (size_t i = 1; i < str2.GetSize(); i++)
    {
        if (str2[i] >= 65 && str2[i] <= 90)
        {
            add[0] = str2[i] + 32;
            add[1] = '\0';
            strcat_s(tmp_str2, strlen(tmp_str2), add);
        }
        else
        {
            add[0] = str2[i];
            add[1] = '\0';
            strcat_s(tmp_str2, strlen(tmp_str2), add);
        }
    }
    isless = std::lexicographical_compare(&tmp_str1[0], &tmp_str1[str1.GetSize()], &tmp_str2[0], &tmp_str2[str2.GetSize()]);
    delete[] add;
    delete[] tmp_str1;
    delete[] tmp_str2;
    return isless;
}

