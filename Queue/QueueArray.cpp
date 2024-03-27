#include "QueueArray.h"

template <class T, int MAX_SIZE>
QueueArray<T, MAX_SIZE>::QueueArray() {
    front = -1; 
    rear = -1;
}

template <class T, int MAX_SIZE>
void QueueArray<T, MAX_SIZE>::enqueue(T element) {
    if (isFull()) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (isEmpty())
        front = 0;
    arr[++rear] = element;
}

template <class T, int MAX_SIZE>
T QueueArray<T, MAX_SIZE>::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return T(); 
    }
    T dequeuedElement = arr[front];
    if (front == rear) 
        front = rear = -1; 
    else
        ++front; 
    return dequeuedElement;
}

template <class T, int MAX_SIZE>
bool QueueArray<T, MAX_SIZE>::isEmpty() {
    return front == -1 && rear == -1;
}

template <class T, int MAX_SIZE>
bool QueueArray<T, MAX_SIZE>::isFull() {
    return rear == MAX_SIZE - 1;
}

template <class T, int MAX_SIZE>
bool QueueArray<T, MAX_SIZE>::underflow() {
    return isEmpty();
}

template <class T, int MAX_SIZE>
bool QueueArray<T, MAX_SIZE>::overflow() {
    return isFull();
}

template <class T, int MAX_SIZE>
void QueueArray<T, MAX_SIZE>::display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
