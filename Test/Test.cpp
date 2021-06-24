// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "String.h"
#include <vector>
#include <string>
#include <algorithm>

bool cmp(const char* str1, const char* str2)
{
    return std::lexicographical_compare(&str1[0], &str1[strlen(str1)], &str2[0], &str2[strlen(str2)]);
}

int main(int argc, char* argv[])
{
    int i = 0;
    char f = ' ';
    std::cout << "Hello World!\n";
    String str1(argv[0]);
    cout << str1 << endl;
    String str2(move(str1));
    str1 = move(str2);

    vector<const char*> str = { "aa", "aaa", "ab", "aaaa", "abc", "aabbcc" };
    std::sort(str.begin(), str.end(), cmp);
    for (auto string : str)
    {
        std::cout << string << " ";
    }

    /*while (i != argc)
    {
        std::cout << argv[i] << "\n";
        i++;
        std::cin >> f;
    }*/
}

