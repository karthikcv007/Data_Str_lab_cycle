#include "LevelOTrav.cpp"
int main() {
  BinaryTree tree;
  // Insert elements into the tree
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);
  tree.insert(7);
  // Perform level-order traversal
  tree.levelOrderTraversal();
  return 0;
}