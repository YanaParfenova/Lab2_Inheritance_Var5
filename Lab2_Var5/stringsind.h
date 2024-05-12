#pragma once

#include "include.h"
#include "strings.h"

class StringInd : public Strings {
public:

    //конструктор без параметров
    StringInd();

    //конструктор с параметром
    StringInd(const char* s);

    //конструктор, принимающий в качестве параметра символ
    StringInd(char c);

    //конструктор копирования
    StringInd(const StringInd& other);

    //перевод всех символов строки в верхний регистр
    void toUpperCase();

    //перевод всех символов строки в нижний регистр
    void toLowerCase();

    //поиск первого вхождения символа в строку
    int findFirstOccurrence(char c);

    //деструктор
    ~StringInd();

    void print() const override;

    std::string getStr() const;

private:
    bool isValidIdentifier(const char* s) const;

    bool isValidIdentifierChar(char c) const;
};

