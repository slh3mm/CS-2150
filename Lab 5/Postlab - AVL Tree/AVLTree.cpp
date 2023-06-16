#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.

int AVLTree::findHeight(AVLNode* n){
  return max(height(n->left),height(n->right)) + 1;
}

int AVLTree::findBalance(AVLNode* n){
  if (n == NULL){
    return 0;
  }
  return height(n->right) - height(n->left);
}

void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  if (!find(x)){
    root = insert(x, root);
  }
}

AVLNode* AVLTree::insert(const string& x, AVLNode*& n){
  if (n == NULL){
    n = new AVLNode();
    n->value = x;
    //printTree();
  }
  else if (x < n->value){
    n->left = insert(x, n->left);
  }
  else if (x > n->value){
    n->right = insert(x, n->right);
  }
  n->height = findHeight(n);
  balance(n);
  
  return n;
}
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return pathTo(x, root);
}

string AVLTree::pathTo(const string& x, AVLNode* node) const{
  if (find(x) == false){
    return "";
  }
  if (node == NULL){
    return "";
  }
  else if (x < node->value){
    return node->value + " " + pathTo(x, node->left);
  }
  else if (x > node->value){
    return node->value + " " + pathTo(x, node->right);
  }
  return node->value;
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return find(x,root);
}

bool AVLTree::find(const string& x, AVLNode* node) const{
  if (node == NULL){
    return false;
  }
  else if (x < node->value){
    return find(x, node->left);
  }
  else if (x > node->value){
    return find(x, node->right);
  }
  return true;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

int AVLTree::numNodes(AVLNode* node) const{
  if (node == NULL){
    return 0;
  }
  else{
    return numNodes(node->left) + numNodes(node->right) + 1;
  }
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  int bal = findBalance(n);
  int leftBal = findBalance(n->left);
  int rightBal = findBalance(n->right);

  if (bal == 2){
    if (rightBal < 0){
      n->right = rotateRight(n->right); 
    }
    n = rotateLeft(n);
    // cout << "Balanced from 2!" << endl;
  }

  else if (bal == -2){
    if (leftBal > 0){
      n->left = rotateLeft(n->left);
    }
    n = rotateRight(n);
    //cout << "Balanced from -2!" << endl;
  }
  
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* tempNode = n->right;
  AVLNode* tempNodeLeft = tempNode->left;
  
  tempNode->left = n;
  n->right = tempNodeLeft;

  n->height = findHeight(n);
  tempNode->height = findHeight(tempNode);

  // cout << "Left Rotation!" << endl;
  
  return tempNode;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* tempNode = n->left;
  AVLNode* tempNodeRight = tempNode->right;
  
  tempNode->right = n;
  n->left = tempNodeRight;

  n->height = findHeight(n);
  tempNode->height = findHeight(tempNode);
  
  // cout << "Right Rotation!" << endl;
  
  return tempNode;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
