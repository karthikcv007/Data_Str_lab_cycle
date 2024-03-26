#include "Stack_LL.h"
template<class T>
Stack_LL<T>::Stack_LL(){
	top=nullptr;
}
template<class T>
Stack_LL<T>::~Stack_LL(){
	Node<T>* temp;
	while(top != nullptr){
		temp=top;
		top=top->next;
		delete temp;
	}
}
template <class T>
void Stack_LL<T>::push(T element){
	Node<T>* newNode =new Node<T>;
	newNode->data=element;
	newNode->next=top;
	top=newNode;
}
template<class T>
T Stack_LL<T>::pop(){
	if(is_empty()){
		cout<<"Stack Underflow\n";
		return T();
	}
	 T poppedElement = top->data;
    Node<T>* temp = top;
    top = top->next;
    delete temp;
    return poppedElement;
}
template<class T>
bool Stack_LL<T>::is_empty(){
	return top == nullptr;
}
template<class T>
bool Stack_LL<T>::is_full(){
	return false;
}
template<class T>
void Stack_LL<T>::display(){
	if(is_empty()){
		cout<<"Stack is empty \n";
		return;
	}
	cout<<"Stack elements  :";
	Node<T>* current =top;
	while(current != nullptr){
		cout<<current->data<<" ";
		current=current->next;
	}
	cout<<endl;
}





