#include "Array2.h"
template<typename T>
Array2<T>::Array2(int limit) {
    this->limit = limit;
    arr = new T[limit];
    size = 0;
}

template<class T>
Array2<T>::~Array2() {
    delete[] arr;
}

template<class T>
void Array2<T>::insert_at_beg(T a) {
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
void Array2<T>::insert_at_end(T a) {
    if (size == limit) {
        cout << "Array is full. Cannot insert element at end." << endl;
        return;
    }
    arr[size] = a;
    ++size;
}

template<class T>
void Array2<T>::insert_at_position(int pos, T a) {
    if (pos < 0 || pos> size) {
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
void Array2<T>::delete_from_beg() {
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
void Array2<T>::delete_from_end() {
    if (size == 0) {
        cout << "Array is empty. Cannot delete element from end." << endl;
        return;
    }
    --size;
}

template<class T>
void Array2<T>::delete_from_position(int pos) {
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
int Array2<T>::find_index(T a) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == a) {
            return i;
        }
    }
    cout<<"No Such Element Found .";
    return -1;
}

template<class T>
void Array2<T>::display() {
    if (size == 0) {
        cout << "Array is empty" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
int Array2<T>::linear_Search(T a) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == a) {
            return i;
        }
    }
    cout<<"Not found .";
    return -1;
}

template<class T>
int Array2<T>::binary_Search(T a) {
    int LB = 0;
    int UB = size - 1;
    while (LB <= UB) {
        int mid = LB + (UB - LB) / 2;
        if (arr[mid] == a) {
            return mid;
        }
        else if (arr[mid] < a) {
            LB = mid + 1;
        }
        else {
            UB = mid - 1;
        }
    }
    cout<<"Not found .";
    return -1;
}

template<class T>
void Array2<T>::bubble_Sort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<class T>
void Array2<T>::insertion_Sort() {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<class T>
void Array2<T>::selection_Sort() {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<class T>
void Array2<T>::merge_Sort(int LB, int UB) {
    if (LB < UB) {
        int mid = LB + (UB - LB) / 2;
        merge_Sort(LB, mid);
        merge_Sort(mid + 1, UB);
        merge(LB, mid, UB);
    }
}

template<class T>
void Array2<T>::merge(int LB, int mid, int UB) {
    int n1 = mid - LB + 1;
    int n2 = UB - mid;

    T left[n1], right[n2];

    for (int i = 0; i < n1; ++i)
        left[i] = arr[LB + i];
    for (int j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = LB;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        }
        else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = left[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

template<class T>
void Array2<T>::quick_Sort(int LB, int UB) {
    if (LB < UB) {
        int pi = partition(LB, UB);
        quick_Sort(LB, pi - 1);
        quick_Sort(pi + 1, UB);
    }
}

template<class T>
int Array2<T>::partition(int LB, int UB) {
    T pivot = arr[UB];
    int i = LB - 1;
    for (int j = LB; j < UB; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[UB]);
    return i + 1;
}

template<class T>    
int Array2<T>::get_Size() {
    return size;
}