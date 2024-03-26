#include <iostream>
using namespace std;

template<class T>
struct Node {
    T coefficient;
    int exponent;
    Node* next;

    Node(T coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

template<class T>
class Polynomial {
private:
    Node<T>* head;

public:
    Polynomial();
    ~Polynomial();
    void insertTerm(T coefficient, int exponent);
    Polynomial<T> add(const Polynomial<T>& other) const;
    Polynomial<T> multiply(const Polynomial<T>& other) const;
    void display() const;
};