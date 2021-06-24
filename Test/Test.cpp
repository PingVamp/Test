// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "String.h"
#include <vector>
#include <string>
#include <algorithm>

bool cmp(String str1, String str2)
{
    char* tmp_str1 = new char[str1.GetSize()+1];
    char* tmp_str2 = new char[str2.GetSize()+1];
    bool isless = false;
    char* add = new char[2];
    if (str1[0] >= 65 && str1[0] <= 90)
    {
        add[0] = str1[0] + 32;
        add[1] = '\0';
        strcpy(tmp_str1, add);
    }
    else
    {
        add[0] = str1[0];
        add[1] = '\0';
        strcpy(tmp_str1, add);
    }
    for (size_t i = 1; i < str1.GetSize(); i++)
    {
        if (str1[i] >= 65 && str1[i] <= 90)
        {
            add[0] = str1[i] + 32;
            add[1] = '\0';
            strcat(tmp_str1, add);
        }
        else
        {
            add[0] = str1[i];
            add[1] = '\0';
            strcat(tmp_str1, add);
        }
    }
    if (str2[0] >= 65 && str2[0] <= 90)
    {
        add[0] = str1[0] + 32;
        add[1] = '\0';
        strcpy(tmp_str2, add);
    }
    else
    {
        add[0] = str2[0];
        add[1] = '\0';
        strcpy(tmp_str2, add);
    }
    for (size_t i = 1; i < str2.GetSize(); i++)
    {
        if (str2[i] >= 65 && str2[i] <= 90)
        {
            add[0] = str2[i] + 32;
            add[1] = '\0';
            strcat(tmp_str2, add);
        }
        else
        {
            add[0] = str2[i];
            add[1] = '\0';
            strcat(tmp_str2, add);
        }
    }
    isless = std::lexicographical_compare(&tmp_str1[0], &tmp_str1[str1.GetSize()], &tmp_str2[0], &tmp_str2[str2.GetSize()]);
    delete[] add;
    delete[] tmp_str1;
    delete[] tmp_str2;
    return isless;
}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    char f = ' ';
    vector<String> strings;
    for (int i = 1; i<argc; i++)
    {
        strings.push_back(String(argv[i]));
    }
    for (auto string : strings)
    {
        cout << string << endl;
    }
    cout << endl;
    std::sort(strings.begin(), strings.end(), cmp);
    for (int i = strings.size() - 1; i >= 0; i--)
    {
        cout << strings[i] << endl;
    }
    //cout << "Чекаем вариант просто нажать энтер" << endl;
    /*cin.get(f);
    if (f == '\n')
    {
        cout << "Просто нажать энтер сработало";
    }
    else
    {
        cout << "Видно не судьба";
    }*/

    /*while (i != argc)
    {
        std::cout << argv[i] << "\n";
        i++;
        std::cin >> f;
    }*/
}

