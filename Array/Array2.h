#include <iostream>
using namespace std;

template<class T>
class Array2 {
private:
    T *arr;
    int limit;
    int size;

public:
    Array2() : limit(100), size(0), arr(new T[limit]) {}
    Array2(int);
    ~Array2();

    void insert_at_beg(T);
    void insert_at_end(T);
    void insert_at_position(int, T);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_position(int);
    int find_index(T);
    void display();

    int linear_Search(T);
    int binary_Search(T);

    void bubble_Sort();
    void insertion_Sort();
    void selection_Sort();
    void merge_Sort(int, int);
    void quick_Sort(int, int);
    int get_Size();

private:
    void merge(int, int, int);
    int partition(int, int);
};