#include "Array3.h"

template<class T>
Array3<T>::Array3() : limit(100), size(0), arr(new T[limit]) {}

template<class T>
Array3<T>::Array3(int limit) : limit(limit), size(0), arr(new T[limit]) {}

template<class T>
Array3<T>::~Array3() {
    delete[] arr;
}

template<class T>
void Array3<T>::insert_at_beg(T a) {
    if (size == limit) {
        cout << "Array is full. Cannot insert element at beginning." << endl;
        return;
    }
    for (int i = size; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = a;
    ++size;
}

template<class T>
void Array3<T>::insert_at_end(T a) {
    if (size == limit) {
        cout << "Array is full. Cannot insert element at end." << endl;
        return;
    }
    arr[size] = a;
    ++size;
}

template<class T>
void Array3<T>::insert_at_position(int pos, T a) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }
    if (size == limit) {
        cout << "Array is full. Cannot insert element at specified position." << endl;
        return;
    }
    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = a;
    ++size;
}

template<class T>
void Array3<T>::delete_from_beg() {
    if (size == 0) {
        cout << "Array is empty. Cannot delete element from beginning." << endl;
        return;
    }
    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
}

template<class T>
void Array3<T>::delete_from_end() {
    if (size == 0) {
        cout << "Array is empty. Cannot delete element from end." << endl;
        return;
    }
    --size;
}

template<class T>
void Array3<T>::delete_from_position(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }
    for (int i = pos; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
}

template<class T>
int Array3<T>::find_index(T a) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == a) {
            return i;
        }
    }
    return -1;
}

template<class T>
void Array3<T>::display() {
    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array as: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
void Array3<T>::left_Rotate() {
    if (size == 0) {
        cout << "Array is empty. Cannot perform left rotation." << endl;
        return;
    }
    T temp = arr[0];
    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}

template<class T>
void Array3<T>::right_Rotate() {
    if (size == 0) {
        cout << "Array is empty. Cannot perform right rotation." << endl;
        return;
    }
    T temp = arr[size - 1];
    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

template<class T>
int Array3<T>::frequency_Count(T a) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == a) {
            ++count;
        }
    }
    return count;
}

template<class T>
int Array3<T>::count_Distinct() {
    int distinctCount = 0;
    for (int i = 0; i < size; ++i) {
        bool isDistinct = true;
        for (int j = 0; j < i; ++j) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            ++distinctCount;
        }
    }
    return distinctCount;
}

template<class T>
int Array3<T>::get_\Size() {
    return size;
}

