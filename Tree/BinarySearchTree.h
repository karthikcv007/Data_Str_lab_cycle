#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
class TreeNode {
 public:
  int key;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};
class BinarySearchTree {
 private:
  TreeNode* root;
  void destroyTree(TreeNode* node);
  TreeNode* insertNode(TreeNode* node, int key);
  TreeNode* deleteNode(TreeNode* node, int key);
  TreeNode* minValueNode(TreeNode* node);
  TreeNode* searchNode(TreeNode* node, int key);
  void inOrderTraversal(TreeNode* node);  // Added in-order traversal method
 public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int key);
  void remove(int key);
  bool search(int key);
  void inOrder();  // Added in-order traversal function
};
#endif