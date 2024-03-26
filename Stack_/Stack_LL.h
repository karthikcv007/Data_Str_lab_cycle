#include<iostream>
using namespace std;
template<class T>
struct Node{
	T data;
	Node<T>* next;
};
template <class T>
class Stack_LL{
	private:
		Node<T>* top;
		public:
			Stack_LL();
			~Stack_LL();
			void push(T element);
			T pop();
			bool is_empty();
			bool is_full();
			void display();
			};