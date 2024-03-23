#include <iostream>
using namespace std;

template<class T>
class Array3{
private:
    T *arr;
    int limit;
    int size;

public:
    Array3();
    Array3(int);
    ~Array3();

    void insert_at_beg(T);
    void insert_at_end(T);
    void insert_at_position(int, T);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_position(int);
    int find_index(T);
    void display();
    void left_Rotate();
    void right_Rotate();
    int frequency_Count(T);
    int count_Distinct();
    int get_Size();
};