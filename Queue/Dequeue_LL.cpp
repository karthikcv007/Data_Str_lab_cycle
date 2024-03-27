#include "Dequeue_LL.h"

template <class T>
Dequeue_LL<T>::Dequeue_LL() {
    front = nullptr;
    rear = nullptr;
}

template <class T>
Dequeue_LL<T>::~Dequeue_LL() {
    Node<T>* temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr; 
}

template <class T>
void Dequeue_LL<T>::insertFront(T element) {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = front;
    if (isEmpty()) {
        rear = newNode;
    }
    front = newNode;
    display();
}

template <class T>
void Dequeue_LL<T>::insertRear(T element) {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
    display();
}

template <class T>
T Dequeue_LL<T>::deleteFront() {
    if (isEmpty()) {
        cout << "DEQUEUE Underflow!\n";
        return T(); 
    }
    T deletedItem = front->data;
    Node<T>* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        rear = nullptr;
    }
    display();
    return deletedItem;
}

template <class T>
T Dequeue_LL<T>::deleteRear() {
    if (isEmpty()) {
        cout << "DEQUEUE Underflow!\n";
        return T(); 
    }
    T deletedItem;
    if (front == rear) {
        deletedItem = front->data;
        delete front;
        front = rear = nullptr;
    } else {
        Node<T>* temp = front;
        while (temp->next != rear) {
            temp = temp->next;
        }
        deletedItem = rear->data;
        delete rear;
        rear = temp;
        rear->next = nullptr;
    }
    display();
    return deletedItem;
}

template <class T>
bool Dequeue_LL<T>::isEmpty() {
    return front == nullptr;
}

template <class T>
void Dequeue_LL<T>::display() {
    if (isEmpty()) {
        cout << "DEQUEUE is empty.\n";
        return;
    }
    cout << "DEQUEUE elements: ";
    Node<T>* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
