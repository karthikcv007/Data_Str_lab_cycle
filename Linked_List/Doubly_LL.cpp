#include "Doubly_LL.h"
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->q;
        delete temp;
    }
}

template<class T>
void DoublyLinkedList<T>::insert_at_beg(T a) {
    Node<T>* newNode = new Node<T>;
    newNode->a = a;
    newNode->p = nullptr;
    newNode->q = head;

    if (head != nullptr) {
        head->p = newNode;
    } else {
        tail = newNode;
    }

    head = newNode;
}

template<class T>
void DoublyLinkedList<T>::insert_at_end(T a) {
    Node<T>* newNode = new Node<T>;
    newNode->a = a;
    newNode->q = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
        newNode->p = nullptr;
    } else {
        tail->q = newNode;
        newNode->p = tail;
        tail = newNode;
    }
}

template<class T>
void DoublyLinkedList<T>::insert_at_position(int pos, T a) {
    if (pos < 0) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }

    if (pos == 0) {
        insert_at_beg(a);
    } else {
        Node<T>* newNode = new Node<T>;
        newNode->a = a;

        Node<T>* current = head;
        int count = 0;

        while (current != nullptr && count < pos - 1) {
            current = current->q;
            ++count;
        }

        if (current == nullptr) {
            cout << "Invalid position. Insertion failed." << endl;
            delete newNode;
            return;
        }

        newNode->q = current->q;
        newNode->p = current;
        if (current->q != nullptr) {
            current->q->p = newNode;
        } else {
            tail = newNode;
        }
        current->q = newNode;
    }
}

template<class T>
void DoublyLinkedList<T>::delete_from_beg() {
    if (head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }

    Node<T>* temp = head;
    head = head->q;
    if (head != nullptr) {
        head->p = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

template<class T>
void DoublyLinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node<T>* temp = tail;
        tail = tail->p;
        tail->q = nullptr;
        delete temp;
    }
}

template<class T>
void DoublyLinkedList<T>::delete_from_position(int pos) {
    if (pos < 0 || head == nullptr) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }

    if (pos == 0) {
        delete_from_beg();
    } else {
        Node<T>* current = head;
        int count = 0;

        while (current != nullptr && count < pos) {
            current = current->q;
            ++count;
        }

        if (current == nullptr) {
            cout << "Invalid position. Deletion failed." << endl;
            return;
        }

        if (current == tail) {
            tail = tail->p;
            tail->q = nullptr;
        } else {
            current->p->q = current->q;
            current->q->p = current->p;
        }

        delete current;
    }
}

template<class T>
void DoublyLinkedList<T>::display() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->a << " ";
        current = current->q;
    }
    cout << endl;
}
