#include "LabCycle2-7.h" 
#include <iostream>
template<typename T>
TwoWayStack<T>::TwoWayStack(int stackSize) { 
    size = stackSize; 
    array = new T[size]; 
    leftTop = -1; 
    rightTop = size;
} 
template<typename T>
TwoWayStack<T>::~TwoWayStack() { 
    delete[] array;
}
template<typename T> 
bool TwoWayStack<T>::isEmpty() { 
    return leftTop == -1 && rightTop == size;
} 
template<typename T> 
bool TwoWayStack<T>::isLeftFull() { 
    return leftTop + 1 == rightTop;
} 
template<typename T> 
bool TwoWayStack<T>::isRightFull() { 
    return rightTop - 1 == leftTop;
}
template<typename T>
void TwoWayStack<T>::pushLeft(const T& element) { 
    if (isLeftFull() || isEmpty()) { 
        std::cout << "Left Stack Overflow" << std::endl;
} else {
    leftTop++; 
    array[leftTop] = element;
   }
}   
template<typename T>
void TwoWayStack<T>::pushRight(const T& element) { 
    if (isRightFull() || isEmpty()) { 
        std::cout << "Right Stack Overflow" << std::endl;
} else {
    rightTop--; array[rightTop] = element;
   } 
} 
template<typename T>
T TwoWayStack<T>::popLeft() { 
    if (leftTop == -1) { 
        std::cout << "Left Stack Underflow" << std::endl; 
        return T(); // Return default value for type T
} else {
    T element = array[leftTop]; 
    leftTop--; return element;
  } 
} 
template<typename T>
T TwoWayStack<T>::popRight() { 
    if (rightTop == size) { 
        std::cout << "Right Stack Underflow" << std::endl; return T(); // Return default value for type T
} else {
    T element = array[rightTop]; 
    rightTop++; return element;
   } 
} 
template<typename T> 
void TwoWayStack<T>::display() { 
    if (isEmpty()) { 
        std::cout << "Two-way Stack is empty" << std::endl;
} else { 
    std::cout << "Left Stack Contents:" << std::endl; 
    for (int i = 0; i <= leftTop; i++) { 
        std::cout << array[i] << std::endl;
   }
   std::cout << "Right Stack Contents:" << std::endl; 
   for (int i = size - 1; i >= rightTop; i--) { 
     std::cout << array[i] << std::endl;
}}}
// Explicit instantiation of the template classes used template class TwoWayStack<int>;

