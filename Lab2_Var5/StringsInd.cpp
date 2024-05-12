#include "include.h"
#include "strings.h"
#include "stringsind.h"
#include <iostream>

    //конструктор без параметров
    StringInd::StringInd() : Strings() {
    }

    //конструктор с параметром
    StringInd::StringInd(const char* s) : Strings(s) {
        if (!isValidIdentifier(s)) {
            clear();
        }
    }

    //конструктор, принимающий в качестве параметра символ
    StringInd::StringInd(char c) : Strings(c) {
        if (!isValidIdentifierChar(c)) {
            clear();
        }
    }

    //конструктор копирования
    StringInd::StringInd(const StringInd& other) : Strings(other) {
    }

    //перевод всех символов строки в верхний регистр
    void StringInd::toUpperCase() {
        for (int i = 0; i < length; ++i) {
            str[i] = std::toupper(str[i]);
        }
    }

    //перевод всех символов строки в нижний регистр
    void StringInd::toLowerCase() {
        for (int i = 0; i < length; ++i) {
            str[i] = std::tolower(str[i]);
        }
    }

    //поиск первого вхождения символа в строку
    int StringInd::findFirstOccurrence(char c) {
        for (int i = 0; i < length; ++i) {
            if (str[i] == c) return i;
        }
        return -1;
    }

    //деструктор
    StringInd::~StringInd() {

    }

    void StringInd::print() const {
        std::cout << "Идентификатор строки: " << str << std::endl;
    }

    std::string StringInd::getStr() const {
        return str;
    }

    bool StringInd::isValidIdentifier(const char* s) const {
        if (!std::isalpha(s[0]) && s[0] != '_') return false;
        for (int i = 1; i < length; ++i) {
            if (!std::isalnum(s[i]) && s[i] != '_') return false;
        }
        return true;
    }

    bool StringInd::isValidIdentifierChar(char c) const {
        return std::isalnum(c) || c == '_';
    }
