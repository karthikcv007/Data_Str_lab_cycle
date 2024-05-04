#ifndef BINARY_TREE_H
#define BINARY_TREE_H
class BinaryTree {
 private:
  int* tree;
  int size;
  void preOrderTraversal(int index);
  void inOrderTraversal(int index);
  void postOrderTraversal(int index);

 public:
  BinaryTree(int maxSize);
  ~BinaryTree();
  void insert(int value);
  void preOrder();
  void inOrder();
  void postOrder();
};
#endif