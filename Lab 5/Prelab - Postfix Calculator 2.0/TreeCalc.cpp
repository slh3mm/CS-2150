// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  TreeNode* tree = this->expressionStack.top();
  cleanTree(tree);
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if (tree != NULL){
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
  }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
  if (val == "+" || val == "-" || val == "/" || val == "*"){
    TreeNode* node1 = expressionStack.top();
    expressionStack.pop();
    
    TreeNode* node2 = expressionStack.top();
    expressionStack.pop();

    TreeNode* operatorNode = new TreeNode(val);
    operatorNode->left = node2;
    operatorNode->right = node1;

    expressionStack.push(operatorNode);
  }
  else{
    TreeNode* operandNode = new TreeNode(val);
    expressionStack.push(operandNode);  
  }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if (tree != NULL){
    cout << tree->value << " ";
    printPrefix(tree->left);
    printPrefix(tree->right);
  }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  if (tree != NULL){
    if (tree->value == "+" || tree->value == "-" || tree->value == "*" ||
	tree->value == "/"){
      cout << "(";
    }
    printInfix(tree->left);
    cout << tree->value;
    printInfix(tree->right);
    if (tree->value == "+" || tree->value == "-" || tree->value == "*" ||
	tree->value == "/"){
      cout << ")";
    }
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if (tree != NULL){
    printPostfix(tree->left);
    printPostfix(tree->right);
    cout << tree->value << " ";
  }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  if (tree != NULL){
    if(tree->left == NULL && tree->right == NULL){
      return stoi(tree->value);
    }
    int leftVal = calculate(tree->left);
    int rightVal = calculate(tree->right);

    if (tree->value == "+"){
      return leftVal + rightVal;
    }
    if (tree->value == "-"){
      return leftVal - rightVal;
    }
    if (tree->value == "/"){
      return leftVal / rightVal;
    }
    return leftVal * rightVal;
  }
  else{
    return 0;
  }
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
  // call private calculate method here
  TreeNode* myNode = this->expressionStack.top();
  int ans = this->calculate(myNode);
  while (this->expressionStack.empty() != 0){
    this->expressionStack.pop();
  }
  return ans;
}
