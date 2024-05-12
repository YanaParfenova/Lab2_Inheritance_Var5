// Lab2_Var5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <Windows.h>
#include "include.h"
#include "strings.h"
#include "stringsind.h"


int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "Введите количество строк: ";
    std::cin >> size;

    Strings** stringsArray = new Strings * [size];

    for (int i = 0; i < size; ++i) {
        int choice;
        std::cout << "\nВыберите тип строки (1 - Строка, 2 - Строка_Идентификатор): ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            char input[100];
            std::cout << "Введите строку: ";
            std::cin.ignore();
            std::cin.getline(input, 100);
            stringsArray[i] = new Strings(input);
            break;
        }
        case 2: {
            char input[100];
            std::cout << "Введите строку_идентификатор: ";
            std::cin.ignore();
            std::cin.getline(input, 100);
            stringsArray[i] = new StringInd(input);
            break;
        }
        default:
            std::cout << "Неверный выбор. Создание пустой строки.\n";
            stringsArray[i] = new Strings();
            break;
        }
    }

    std::cout << "\nПроверка методов производных классов:\n";
    for (int i = 0; i < size; ++i) {
        StringInd* stringIndPtr = dynamic_cast<StringInd*>(stringsArray[i]);
        if (stringIndPtr) {
            std::cout << "Строка_Идентификатор: " << stringIndPtr->getStr() << "\n";
            stringIndPtr->toUpperCase();
            std::cout << "Верхний регистр: " << stringIndPtr->getStr() << "\n";
            stringIndPtr->toLowerCase();
            std::cout << "Нижний регистр: " << stringIndPtr->getStr() << "\n";
            char c;
            std::cout << "Введите символ для поиска: ";
            std::cin >> c;
            int pos = stringIndPtr->findFirstOccurrence(c);
            if (pos != -1) {
                std::cout << "Первое вхождение символа '" << c << "' на позиции " << pos << "\n";
            }
            else {
                 std::cout << "Символ '" << c << "' не найден\n";
            }
        }
        else {
            std::cout << "Обычная строка: " << stringsArray[i]->getStr() << "\n";
        }
    }

   for (int i = 0; i < size; ++i) {
        delete stringsArray[i];
    }
   delete[] stringsArray;

    return 0;
  
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
