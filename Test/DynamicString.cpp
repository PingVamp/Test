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
    delete[] _string;
	_size = strlen(str) + 1;
	_string = new char[_size];
	strcpy_s(_string, _size, str);

    return *this;
}

DynamicString& DynamicString::operator=(const DynamicString& other)
{
    delete[] _string;
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

char& DynamicString::operator[](size_t index)
{
    return _string[index];
}

std::ostream& operator<<(std::ostream& os, const DynamicString& str)
{
	os << str._string;
	return os;
}

DynamicString operator+(DynamicString str1, DynamicString str2)
{
    int str1Size = str1.GetSize();
    int str2Size = str2.GetSize();
	char* sum = new char[str1Size + str2Size];
	strcpy_s(sum, sizeof(char) * (str1Size + str2Size), str1.GetString());
	strcat_s(sum, sizeof(char)*(str1Size + str2Size), str2.GetString());
	DynamicString str(sum);
	delete[] sum;
	return str;
}

DynamicString operator+(const char* str1, DynamicString str2)
{
    int str1Size = strlen(str1);
    int str2Size = str2.GetSize();
    char* sum = new char[str1Size + str2Size];
    strcpy_s(sum, sizeof(char) * (str1Size + str2Size), str1);
    strcat_s(sum, sizeof(char) * (str1Size + str2Size), str2.GetString());
    DynamicString str(sum);
    delete[] sum;
    return str;
}

DynamicString operator+(DynamicString str1, const char* str2)
{
    int str1Size = str1.GetSize();
    int str2Size = strlen(str2);
    char* sum = new char[str1Size + str2Size];
    strcpy_s(sum, sizeof(char) * (str1Size + str2Size), str1.GetString());
    strcat_s(sum, sizeof(char) * (str1Size + str2Size), str2);
    DynamicString str(sum);
    delete[] sum;
    return str;
}

bool cmp(DynamicString str1, DynamicString str2)    //Функция лексикографического сравнения двух строк без учета регистра
{
    int tmp_str1Size = str1.GetSize();
    int tmp_str2Size = str2.GetSize();
    char* tmp_str1 = new char[tmp_str1Size];
    char* tmp_str2 = new char[tmp_str2Size];
    bool isless = false;
    for (size_t i = 0; i < str1.GetSize()-1; i++)
    {
        if (str1[i] >= 65 && str1[i] <= 90)
        {
            tmp_str1[i] = str1[i] + 32;
        }
        else
        {
            tmp_str1[i] = str1[i];
        }
    }
    tmp_str1[tmp_str1Size-1] = '\0';
    for (size_t i = 0; i < str2.GetSize()-1; i++)
    {
        if (str2[i] >= 65 && str2[i] <= 90)
        {
            tmp_str2[i] = str2[i]+32;
        }
        else
        {
            tmp_str2[i] = str2[i];
        }
    }
    tmp_str2[tmp_str2Size-1] = '\0';
    isless = std::lexicographical_compare(&tmp_str1[0], &tmp_str1[str1.GetSize()], &tmp_str2[0], &tmp_str2[str2.GetSize()]);
    delete[] tmp_str2;
    delete[] tmp_str1;
    return isless;
}

