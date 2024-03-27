#include "Queue_LL.h"
#include <iostream>

using namespace std;

template <class T>
Queue_LL<T>::Queue_LL() {
    front = nullptr;
    rear = nullptr;
}

template <class T>
Queue_LL<T>::~Queue_LL() {
    Node<T>* temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr; 
}

template <class T>
void Queue_LL<T>::enqueue(T element) {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template <class T>
T Queue_LL<T>::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return T(); 
    }
    T dequeuedElement = front->data;
    Node<T>* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr; 
    }
    delete temp;
    return dequeuedElement;
}

template <class T>
bool Queue_LL<T>::isEmpty() {
    return front == nullptr;
}

template <class T>
bool Queue_LL<T>::isFull() {
    return false; 
}

template <class T>
bool Queue_LL<T>::underflow() {
    return isEmpty();
}

template <class T>
bool Queue_LL<T>::overflow() {
    return false;
}

template <class T>
void Queue_LL<T>::display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    Node<T>* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
