#include <iostream>
#include <queue>

#include "LevelOTrav.h"
TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
BinaryTree::BinaryTree() : root(nullptr) {}
BinaryTree::~BinaryTree() {
  // Implement destructor to free allocated memory
}
void BinaryTree::insert(int val) {
  // Implement insertion logic
}
void BinaryTree::levelOrderTraversal() {
  if (root == nullptr) {
    return;
  }
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* current = q.front();
    q.pop();
    std::cout << current->data << " ";
    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }
  }
}