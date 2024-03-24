#include <iostream>
using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;
    
    Node(const T& p) : data(p), next(nullptr) {}
};

template<class T>
class LinkedList {
private:
    Node<T>* head;
    
public:
    LinkedList();
    ~LinkedList();
    
    void insert_at_beg(const T&);
    void insert_at_end(const T&);
    void insert_at_position(int, const T&);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_position(int);
    void display();
};