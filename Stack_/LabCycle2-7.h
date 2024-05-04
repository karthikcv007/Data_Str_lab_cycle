#ifndef TWOWAYSTACK_H 
#define TWOWAYSTACK_H

template<typename T> 
class TwoWayStack { 
    private:
       T* array; 
       int size; 
       int leftTop; 
       int rightTop;
    public:
       TwoWayStack(int stackSize); 
       ~TwoWayStack(); 
       bool isEmpty(); 
       bool isLeftFull(); 
       bool isRightFull(); 
       void pushLeft(const T& element); 
       void pushRight(const T& element);
       T popLeft(); 
       T popRight(); 
       void display();
};
#endif // TWOWAYSTACK_H
