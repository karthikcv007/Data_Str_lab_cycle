#include "Array1.h"
using namespace std;

template<class T>
Array1<T>::Array1() {
    size = 0;
}

template<class T>
bool Array1<T>::is_empty() {
    return size == 0;
}

template<class T>
bool Array1<T>::is_full() {
    return size == 100;
}

template<class T>
void Array1<T>::insert_at_beg(T a) {
    if (!is_full()) {
        for (int i = size; i > 0; --i)
            arr[i] = arr[i - 1];
        arr[0] = a;
        ++size;
    } else {
        cout << "Array is full. Cannot insert at beginning." << endl;
    }
}

template<class T>
void Array1<T>::insert_at_end(T a) {
    if (!is_full()) {
        arr[size++] = a;
    } else {
        cout << "Array is full. Cannot insert at end." << endl;
    }
}

template<class T>
void Array1<T>::insert_at_position(int pos, T a) {
    if (pos >= 0 && pos <= size && !is_full()) {
        for (int i = size; i > pos; --i)
            arr[i] = arr[i - 1];
        arr[pos] = a;
        ++size;
    } else {
        cout << "Invalid pos or array is full. Cannot insert at specified pos." << endl;
    }
}

template<class T>
void Array1<T>::delete_from_beg() {
    if (!is_empty()) {
        for (int i = 0; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        --size;
    } else {
        cout << "Array is empty. Cannot delete from beginning." << endl;
    }
}

template<class T>
void Array1<T>::delete_from_end() {
    if (!is_empty()) {
        --size;
    } else {
        cout << "Array is empty. Cannot delete from end." << endl;
    }
}

template<class T>
void Array1<T>::delete_from_position(int pos) {
    if (pos >= 0 && pos < size) {
        for (int i = pos; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        --size;
    } else {
        cout << "Invalid position. Cannot delete from specified position." << endl;
    }
}

template<class T>
int Array1<T>::find_index(T a) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == a)
            return i;
    }
    cout<<"No Element ";
    return -1;
}

template<class T>
void Array1<T>::display() {
    if (!is_empty()) {
        cout << "Array : ";
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    } else {
        cout << "Array is empty." << endl;
    }
}