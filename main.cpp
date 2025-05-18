#include "array.h"

int main() {
    Array arr1, arr2;
    arr1.setValue(6);
    arr1.setValue(60);
    arr2.setValue(40);
    arr2.setValue(40);

    if (arr1 == arr2) {
        cout << "Eq" << endl;
    }
    if (arr1 != arr2) {
        cout << "Not Eq" << endl;
    }

    Array arr3 = arr1 + arr2;
    cout << "arr3: " << arr3;

    Array arr4 = arr1 + 7;
    cout << "arr1 + 7: " << arr4;

    Array arr5 = 7 + arr1;
    cout << "7 + arr1: " << arr5;

    Array arr6 = arr1 - 3;
    cout << "arr1 - 3: " << arr6;

    arr1++;
    cout << "arr1++: " << arr1;

    arr1 += 2;
    cout << "arr1 += 2: " << arr1;

    cout << "arr1[0]: " << arr1[0] << endl;
    cout << "arr1[10] (out of bounds): " << arr1[10] << endl;

    return 0;
}