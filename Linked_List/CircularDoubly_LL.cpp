#include "CircularDoubly_LL.h"

template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() : head(nullptr) {}

template<class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    if (head != nullptr) {
        Node* temp = head->q;
        while (temp != head) {
            Node* q = temp->q;
            delete temp;
            temp = q;
        }
        delete head;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::insert_at_beg(T data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        newNode->p = newNode;
        newNode->q = newNode;
    } else {
        Node* last = head->p;
        newNode->q = head;
        head->p = newNode;
        newNode->p = last;
        last->q = newNode;
        head = newNode;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::insert_at_end(T data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        newNode->p = newNode;
        newNode->q = newNode;
    } else {
        Node* last = head->p;
        newNode->q = head;
        head->p = newNode;
        newNode->p = last;
        last->q = newNode;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::insert_at_position(int pos, T data) {
    if (pos < 0) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }

    if (pos == 0) {
        insert_at_beg(data);
    } else {
        Node* newNode = new Node;
        newNode->data = data;

        Node* current = head;
        int count = 0;

        while (current->q != head && count < pos - 1) {
            current = current->q;
            ++count;
        }

        newNode->q = current->q;
        newNode->p = current;
        current->q->p = newNode;
        current->q = newNode;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::delete_from_beg() {
    if (head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }

    if (head->q == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        Node* last = head->p;
        head = head->q;
        head->p = last;
        last->q = head;
        delete temp;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }

    if (head->q == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head->p;
        Node* p = temp->p;
        p->q = head;
        head->p = p;
        delete temp;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::delete_from_position(int pos) {
    if (head == nullptr || pos < 0) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }

    if (pos == 0) {
        delete_from_beg();
    } else {
        Node* current = head;
        int count = 0;

        while (current->q != head && count < pos) {
            current = current->q;
            ++count;
        }

        if (count < pos) {
            cout << "Invalid position. Deletion failed." << endl;
            return;
        }

        Node* p = current->p;
        p->q = current->q;
        current->q->p = p;
        delete current;
    }
}

template<class T>
void CircularDoublyLinkedList<T>::display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->q;
    } while (temp != head);
    cout << endl;
}
