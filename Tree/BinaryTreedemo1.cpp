#include "BinaryTree1.cpp"
using namespace std;
int main() {
  BinaryTree<int> tree;
  tree.insertNode(50);
  tree.insertNode(30);
  tree.insertNode(70);
  tree.insertNode(20);
  tree.insertNode(40);
  tree.insertNode(60);
  tree.insertNode(80);
  cout << "Preorder traversal: ";
  tree.preOrder();
  cout << "Inorder traversal: ";
  tree.inOrder();
  cout << "Postorder traversal: ";
  tree.postOrder();
  return 0;
}