#include <iostream>
using namespace std;

template<class T>
class Array1 {
private:
    T arr[100];
    int size;

public:
    Array1();
    bool is_empty();
    bool is_full();
    void insert_at_beg(T);
    void insert_at_end(T);
    void insert_at_position(int, T);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_position(int);
    int find_index(T);
    void display();
};