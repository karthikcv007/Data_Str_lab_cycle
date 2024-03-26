#include <iostream>
using namespace std;

template<class T>
class CircularDoublyLinkedList {
private:
    struct Node {
        T data;
        Node* p;
        Node* q;
    };
    Node* head;
public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    void insert_at_beg(T data);
    void insert_at_end(T data);
    void insert_at_position(int pos, T data);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_position(int pos);
    void display();
};

