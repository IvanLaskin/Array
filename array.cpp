#include "array.h"
#include <algorithm>

void Array::showElements() const {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

Array::Array() : data(nullptr), size(0) {}
Array::Array(const Array& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Array::~Array() {
    delete[] data;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

void Array::setValue(int value) {
    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    ++size;
}

int Array::getSize() const {
    return size;
}

Array Array::operator+(const Array& other) const {
    Array result;
    for (int i = 0; i < size; ++i) result.setValue(data[i]);
    for (int i = 0; i < other.size; ++i) result.setValue(other.data[i]);
    return result;
}

Array Array::operator+(int value) const {
    Array result;
    for (int i = 0; i < size; ++i) result.setValue(data[i] + value);
    return result;
}

Array Array::operator-(int value) const {
    Array result;
    for (int i = 0; i < size; ++i) result.setValue(data[i] - value);
    return result;
}

bool Array::operator==(const Array& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

Array Array::operator++(int) {
    Array temp(*this);
    for (int i = 0; i < size; ++i) ++data[i];
    return temp;
}

Array& Array::operator+=(int value) {
    for (int i = 0; i < size; ++i) data[i] += value;
    return *this;
}

int Array::operator[](int index) const {
    if (index >= 0 && index < size) return data[index];
    return data[0];
}

ostream& operator<<(ostream& os, const Array& arr) {
    for (int i = 0; i < arr.size; ++i) {
        os << arr.data[i] << " ";
    }
    os << endl;
    return os;
}

Array operator+(int value, const Array& arr) {
    Array result;
    for (int i = 0; i < arr.size; ++i) result.setValue(value + arr.data[i]);
    return result;
}