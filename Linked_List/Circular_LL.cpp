#include "Circular_LL.h"

template<class T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr) {}

template<class T>
CircularLinkedList<T>::~CircularLinkedList() {
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
void CircularLinkedList<T>::insert_at_beg(T a) {
    Node* newNode = new Node;
    newNode->a = a;
    if (head == nullptr) {
        head = newNode;
        newNode->q = newNode;
    } else {
        Node* last = head;
        while (last->q != head) {
            last = last->q;
        }
        newNode->q = head;
        head = newNode;
        last->q = newNode;
    }
}

template<class T>
void CircularLinkedList<T>::insert_at_end(T a) {
    Node* newNode = new Node;
    newNode->a = a;
    if (head == nullptr) {
        head = newNode;
        newNode->q = newNode;
    } else {
        Node* last = head;
        while (last->q != head) {
            last = last->q;
        }
        last->q = newNode;
        newNode->q = head;
    }
}

template<class T>
void CircularLinkedList<T>::insert_at_position(int pos, T a) {
    if (pos < 0) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }

    if (pos == 0) {
        insert_at_beg(a);
    } else {
        Node* newNode = new Node;
        newNode->a = a;

        Node* current = head;
        int count = 0;

        while (current->q != head && count < pos - 1) {
            current = current->q;
            ++count;
        }

        newNode->q = current->q;
        current->q = newNode;
    }
}

template<class T>
void CircularLinkedList<T>::delete_from_beg() {
    if (head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }

    if (head->q == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        Node* last = head;
        while (last->q != head) {
            last = last->q;
        }
        head = head->q;
        last->q = head;
        delete temp;
    }
}

template<class T>
void CircularLinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }

    if (head->q == head) {
        delete head;
        head = nullptr;
    } else {
        Node* prev = nullptr;
        Node* temp = head;
        while (temp->q != head) {
            prev = temp;
            temp = temp->q;
        }
        prev->q = head;
        delete temp;
    }
}

template<class T>
void CircularLinkedList<T>::delete_from_position(int pos) {
    if (head == nullptr || pos < 0) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }

    if (pos == 0) {
        delete_from_beg();
    } else {
        Node* prev = nullptr;
        Node* current = head;
        int count = 0;

        while (current->q != head && count < pos) {
            prev = current;
            current = current->q;
            ++count;
        }

        if (count < pos) {
            cout << "Invalid position. Deletion failed." << endl;
            return;
        }

        prev->q = current->q;
        delete current;
    }
}

template<class T>
void CircularLinkedList<T>::display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->a << " ";
        temp = temp->q;
    } while (temp != head);
    cout << endl;
}