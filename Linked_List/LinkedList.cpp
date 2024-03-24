#include "LinkedList.h"
template<class T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template<class T>
void LinkedList<T>::insert_at_beg(const T& p) {
    Node<T>* newNode = new Node<T>(p);
    newNode->next = head;
    head = newNode;
}

template<class T>
void LinkedList<T>::insert_at_end(const T& p) {
    Node<T>* newNode = new Node<T>(p);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

template<class T>
void LinkedList<T>::insert_at_position(int pos, const T& p) {
    if (pos < 0) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }
    if (pos == 0) {
        insert_at_beg(p);
        return;
    }
    Node<T>* newNode = new Node<T>(p);
    Node<T>* current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

template<class T>
void LinkedList<T>::delete_from_beg() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from beginning." << endl;
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template<class T>
void LinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from end." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

template<class T>
void LinkedList<T>::delete_from_position(int pos) {
    if (head == nullptr || pos < 0) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }
    if (pos == 0) {
        delete_from_beg();
        return;
    }
    Node<T>* current = head;
    for (int i = 0; i < pos - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }
    if (current->next == nullptr) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }
    Node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template<class T>
void LinkedList<T>::display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node<T>* current = head;
    cout << "List elements: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}