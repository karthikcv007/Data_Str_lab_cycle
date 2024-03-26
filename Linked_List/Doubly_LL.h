#include <iostream>
using namespace std;

template<class T>
struct Node {
    T a;
    Node<T>* p;
    Node<T>* q;
};

template<class T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert_at_beg(T a);
    void insert_at_end(T a);
    void insert_at_position(int pos, T a);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_position(int pos);
    void display();
};