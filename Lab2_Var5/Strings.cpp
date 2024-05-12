#include "include.h"
#include "strings.h"
#include <iostream>

    //конструктор без параметров
    Strings::Strings() : str(nullptr), length(0) {

    }

    //конструктор с параметром
    Strings::Strings(const char* s) : length(std::strlen(s)) {
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    //конструктор, принимающий в качестве параметра символ
    Strings::Strings(char c) : length(1) {
        str = new char[2];
        str[0] = c;
        str[1] = '\0';
    }

    //конструктор копирования
    Strings::Strings(const Strings& other) : length(other.length) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    //получение длины строки
    int  Strings::getLength() {
        return length;
    }

    //очистка строки (сделать строку пустой);
    void  Strings::clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    //деструктор
    Strings::~Strings() {
        delete[] str;
    }

    //возвращает строку
    std::string  Strings::getStr() const {
        return str;
    }

    Strings& Strings::operator=(const Strings& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    Strings  Strings::operator+(const Strings& other) const {
        Strings result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        std::strcpy(result.str, str);
        std::strcat(result.str, other.str);
        return result;
    }

    Strings  Strings::operator-(const Strings& other) const {
        Strings result = *this;
        for (int i = 0; i < other.length; ++i) {
            result.removeChar(other.str[i]);
        }
        return result;
    }

    void Strings::print() const {
        std::cout << "Строка: " << str << std::endl;
    }

    bool  Strings::operator>(const Strings& other) const {
        int minLength = (length < other.length) ? length : other.length;
        for (int i = 0; i < minLength; ++i) {
            if (str[i] > other.str[i]) return true;
            if (str[i] < other.str[i]) return false;
        }
        return (length > other.length);
    }

    bool  Strings::operator<(const Strings& other) const {
        int minLength = (length < other.length) ? length : other.length;
        for (int i = 0; i < minLength; ++i) {
            if (str[i] < other.str[i]) return true;
            if (str[i] > other.str[i]) return false;
        }
        return (length < other.length);
    }



    void  Strings::removeChar(char c) {
        char* temp = new char[length + 1];
        int j = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] != c) {
                temp[j++] = str[i];
            }
        }
        temp[j] = '\0';
        delete[] str;
        str = temp;
        length = j;
    }

