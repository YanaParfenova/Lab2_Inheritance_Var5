#pragma once

#include "include.h"

class Strings {
protected:
    char* str;
    int length;

public:
    //конструктор без параметров
    Strings();

    //конструктор с параметром
    Strings(const char* s);

    //конструктор, принимающий в качестве параметра символ
    Strings(char c);

    //конструктор копирования
    Strings(const Strings& other);
    
    //получение длины строки
    int getLength();

    //очистка строки (сделать строку пустой);
    void clear();

    //деструктор
    ~Strings();

    //возвращает строку
    std::string getStr() const;

    Strings& operator=(const Strings& other);

    Strings operator+(const Strings& other) const;

    Strings operator-(const Strings& other) const;

    virtual void print() const;

    bool operator>(const Strings& other) const;

    bool operator<(const Strings& other) const;


private:
    void removeChar(char c);
};