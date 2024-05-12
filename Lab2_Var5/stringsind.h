#pragma once

#include "include.h"
#include "strings.h"

class StringInd : public Strings {
public:

    //����������� ��� ����������
    StringInd();

    //����������� � ����������
    StringInd(const char* s);

    //�����������, ����������� � �������� ��������� ������
    StringInd(char c);

    //����������� �����������
    StringInd(const StringInd& other);

    //������� ���� �������� ������ � ������� �������
    void toUpperCase();

    //������� ���� �������� ������ � ������ �������
    void toLowerCase();

    //����� ������� ��������� ������� � ������
    int findFirstOccurrence(char c);

    //����������
    ~StringInd();

    void print() const override;

    std::string getStr() const;

private:
    bool isValidIdentifier(const char* s) const;

    bool isValidIdentifierChar(char c) const;
};

