// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DynamicString.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    std::vector<DynamicString> strings;      //Вектор строк
    for (int i = 1; i<argc; i++)        //Считывание аргументов коммандной строки с записью их в массив строк
    {
        strings.push_back(DynamicString(argv[i]));
    }
    int BUFFER_SIZE = 20;
    char* buff = new char[BUFFER_SIZE];          //Буффер для пользовательского ввода
    bool exit = false;                  //Переменная для проверки на выход
    while (!exit)                       
    {
        BUFFER_SIZE = 20;
        delete[] buff;
        buff = new char[BUFFER_SIZE];
        std::cout << "Введите размер строки" << std::endl;
        std::cout << "Введите q для выхода" << std::endl;
        std::cout << "Введите l для вывода введенных строк в обратном лексикографическом порядке" << std::endl;
        std::cin.getline(buff, 20);
        if (buff[0] == 'q')             //Выход если пользователь решил выйти
        {
            exit = true;
            delete[] buff;
            continue;
        }
        if (buff[0] == 'l')             //Сортировка в лексикографическом порядке и вывод в обратном
        {
            std::sort(strings.begin(), strings.end(), cmp);
            for (auto it = strings.rbegin(); it != strings.rend(); ++it)
            {
                std::cout << *it << std::endl;
            }
            continue;
        }
        else
        {
            std::stringstream strValue;
            strValue << buff;
            strValue >> BUFFER_SIZE;       //Перевод символьного ввода в int
            if (BUFFER_SIZE == 0)          //Если пользователь не ввел число, возващение в началало цикла
            {
                std::cout << "Введите размер строки числом" << std::endl;
                continue;
            }
            delete[] buff;
            buff = new char[BUFFER_SIZE +1];    //Создание буффера для ввода в соответствие с введенным пользователем числом
            std::cout << "Введите строку" << std::endl;
            std::cin.getline(buff, BUFFER_SIZE+1);
            strings.push_back(DynamicString(buff));     //Считывание строки и запись в вектор
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');       //Очистка потока от мусора на случай избыточного ввода пользователя

        }
    }
}

