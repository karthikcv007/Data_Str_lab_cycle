#include "BinaryTree1.h"
using namespace std;
template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}
template <typename T>
BinaryTree<T>::~BinaryTree() {
  destroyTree(root);
}
template <typename T>
void BinaryTree<T>::destroyTree(TreeNode<T>* node) {
  if (node) {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}
template <typename T>
void BinaryTree<T>::insertNode(T val) {
  TreeNode<T>* newNode = new TreeNode<T>(val);
  if (!root) {
    root = newNode;
  } else {
    TreeNode<T>* current = root;
    TreeNode<T>* parent;
    while (true) {
      parent = current;
      if (val < current->data) {
        current = current->left;
        if (!current) {
          parent->left = newNode;
          return;
        }
      } else {
        current = current->right;
        if (!current) {
          parent->right = newNode;
          return;
        }
      }
    }
  }
}
template <typename T>
void BinaryTree<T>::preOrderTraversal(TreeNode<T>* node) {
  if (node) {
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}
template <typename T>
void BinaryTree<T>::preOrder() {
  preOrderTraversal(root);
  cout << endl;
}
template <typename T>
void BinaryTree<T>::inOrderTraversal(TreeNode<T>* node) {
  if (node) {
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
  }
}
template <typename T>
void BinaryTree<T>::inOrder() {
  inOrderTraversal(root);
  cout << endl;
}
template <typename T>
void BinaryTree<T>::postOrderTraversal(TreeNode<T>* node) {
  if (node) {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
  }
}
template <typename T>
void BinaryTree<T>::postOrder() {
  postOrderTraversal(root);
  cout << endl;
}