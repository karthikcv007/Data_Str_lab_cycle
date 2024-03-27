#include<iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class Dequeue_LL {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Dequeue_LL();
    ~Dequeue_LL();
    void insertFront(T element); 
    void insertRear(T element);
    T deleteFront();
    T deleteRear(); 
    bool isEmpty();
    void display(); 
};
