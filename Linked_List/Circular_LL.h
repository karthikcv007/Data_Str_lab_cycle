#include <iostream>
using namespace std;

template<class T>
class CircularLinkedList {
private:
    struct Node {
        T a;
        Node* q;
    };
    Node* head;
public:
    CircularLinkedList();
    ~CircularLinkedList();

    void insert_at_beg(T a);
    void insert_at_end(T a);
    void insert_at_position(int pos, T a);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_position(int pos);
    void display();
};