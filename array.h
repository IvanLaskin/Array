#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
    int* data; // вказівник на динамічний масив
    int size; // кількість елементів у масиві

public:
    Array();                               // конструктор за замовчуванням
    Array(const Array& other);             // конструктор копіювання
    ~Array();                             // деструктор

    Array& operator=(const Array& other); // оператор присвоєння

    void setValue(int value);            // додає елемент в кінець масиву
    int getSize() const;                 // повертає розмір масиву
    void showElements() const;           // вивід масиву у консоль

    // Оператори
    Array operator+(const Array& other) const; // склеювання масивів
    Array operator+(int value) const;          // додавання числа до кожного елемента
    Array operator-(int value) const;          // віднімання числа від кожного елемента
    bool operator==(const Array& other) const; // порівняння на рівність
    bool operator!=(const Array& other) const; // порівняння на нерівність
    Array operator++(int);                     // постфіксний інкремент
    Array& operator+=(int value);              // додавання з присвоєнням
    int operator[](int index) const;           // доступ з індексом

    //Друзі класу
    friend ostream& operator<<(ostream& os, const Array& arr); // вивід
    friend Array operator+(int value, const Array& arr);       // 7 + arr
};

#endif
