#include <iostream>

#include "BinarySearchTree.cpp"
int main() {
  BinarySearchTree bst;
  bst.insert(50);
  bst.insert(30);
  bst.insert(20);
  bst.insert(40);
  bst.insert(70);
  bst.insert(60);
  bst.insert(80);
  std::cout << "In-order traversal after insertion: ";
  bst.inOrder();
  std::cout << std::endl;
  std::cout << "Searching for 40: " << std::boolalpha << bst.search(40)
            << std::endl;
  std::cout << "Searching for 90: " << std::boolalpha << bst.search(90)
            << std::endl;
  bst.remove(30);
  std::cout << "In-order traversal after deletion: ";
  bst.inOrder();
  std::cout << std::endl;
  return 0;
}