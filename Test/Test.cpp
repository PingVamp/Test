// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DynamicString.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    char* buff = new char[20];          //Буффер для пользовательского ввода
    vector<DynamicString> strings;      //Вектор строк
    for (int i = 1; i<argc; i++)        //Считывание аргументов коммандной строки с записью их в массив строк
    {
        strings.push_back(DynamicString(argv[i]));
    }
    int buffSize = 0;
    bool exit = false;                  //Переменная для проверки на выход
    while (!exit)                       
    {
        delete[] buff;
        buff = new char[20];
        cout << "Введите размер строки" << endl;
        cout << "Введите q для выхода" << endl;
        cout << "Введите l для вывода введенных строк в обратном лексикографическом порядке" << endl;
        cin.getline(buff, 20);
        if (buff[0] == 'q')             //Выход если пользователь решил выйти
        {
            exit = true;
            delete[] buff;
            continue;
        }
        if (buff[0] == 'l')             //Сортировка в лексикографическом порядке и вывод в обратном
        {
            std::sort(strings.begin(), strings.end(), cmp);
            for (int i = strings.size() - 1; i >= 0; i--)
            {
                cout << strings[i] << endl;
            }
        }
        else
        {
            stringstream strValue;
            strValue << buff;
            strValue >> buffSize;       //Перевод символьного ввода в int
            if (buffSize == 0)          //Если пользователь не ввел число, возващение в началало цикла
            {
                cout << "Введите размер строки числом" << endl;
                continue;
            }
            delete[] buff;
            buff = new char[buffSize+1];    //Создание буффера для ввода в соответствие с введенным пользователем числом
            cout << "Введите строку" << endl;
            cin.getline(buff, buffSize);
            strings.push_back(DynamicString(buff));     //Считывание строки и запись в вектор
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');       //Очистка потока от мусора на случай избыточного ввода пользователя

        }
    }
}

