#pragma once

#include "include.h"

class Strings {
protected:
    char* str;
    int length;

public:
    //����������� ��� ����������
    Strings();

    //����������� � ����������
    Strings(const char* s);

    //�����������, ����������� � �������� ��������� ������
    Strings(char c);

    //����������� �����������
    Strings(const Strings& other);
    
    //��������� ����� ������
    int getLength();

    //������� ������ (������� ������ ������);
    void clear();

    //����������
    ~Strings();

    //���������� ������
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