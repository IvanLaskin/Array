#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
    int* data; // �������� �� ��������� �����
    int size; // ������� �������� � �����

public:
    Array();                               // ����������� �� �������������
    Array(const Array& other);             // ����������� ���������
    ~Array();                             // ����������

    Array& operator=(const Array& other); // �������� ���������

    void setValue(int value);            // ���� ������� � ����� ������
    int getSize() const;                 // ������� ����� ������
    void showElements() const;           // ���� ������ � �������

    // ���������
    Array operator+(const Array& other) const; // ���������� ������
    Array operator+(int value) const;          // ��������� ����� �� ������� ��������
    Array operator-(int value) const;          // �������� ����� �� ������� ��������
    bool operator==(const Array& other) const; // ��������� �� ������
    bool operator!=(const Array& other) const; // ��������� �� ��������
    Array operator++(int);                     // ����������� ���������
    Array& operator+=(int value);              // ��������� � ����������
    int operator[](int index) const;           // ������ � ��������

    //���� �����
    friend ostream& operator<<(ostream& os, const Array& arr); // ����
    friend Array operator+(int value, const Array& arr);       // 7 + arr
};

#endif
