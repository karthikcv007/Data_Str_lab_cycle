#include "LabCycle2-7.cpp" 
#include <iostream>
void displayMenu() { 
    std::cout << "Menu:" << std::endl; 
    std::cout << "1. Push Left" << std::endl; 
    std::cout << "2. Push Right" << std::endl; 
    std::cout << "3. Pop Left" << std::endl; 
    std::cout << "4. Pop Right" << std::endl; 
    std::cout << "5. Display Stack" << std::endl; 
    std::cout << "6. Exit" << std::endl; 
    std::cout << "Enter your choice: ";
} 
int main() {
    TwoWayStack<int> stack(5); 
    int choice; 
    int element;
do {
    displayMenu(); 
    std::cin >> choice;
    switch (choice) { 
        case 1:
            std::cout << "Enter element to push left: "; 
            std::cin >> element; 
            stack.pushLeft(element); 
        break;
        case 2:
            std::cout << "Enter element to push right: "; 
            std::cin >> element; 
            stack.pushRight(element); 
            break;
        case 3: 
            std::cout << "Popped Left: " << stack.popLeft() << std::endl; 
            break;
        case 4: 
            std::cout << "Popped Right: " << stack.popRight() << std::endl; 
            break;
        case 5:
            stack.display();
            break;
        case 6: 
            std::cout << "Exiting program." << std::endl; 
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl; }
} while (choice != 6);
  
return 0;
}

