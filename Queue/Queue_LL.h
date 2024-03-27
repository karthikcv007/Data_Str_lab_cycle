#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class Queue_LL {
private:
    Node<T>* front; 
    Node<T>* rear; 

public:
    Queue_LL(); 
    ~Queue_LL();
    void enqueue(T element); 
    T dequeue(); 
    bool isEmpty(); 
    bool isFull(); 
    bool underflow(); 
    bool overflow(); 
    void display(); 
};
