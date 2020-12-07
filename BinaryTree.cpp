//binary tree node class. contains left and right pointer
#include "BinaryTree.h"
#include <iostream>
#include <cstring>
using namespace std;

void btNode::setData(char *inputdata){
  strcpy(data, inputdata);
}

void btNode::setRightPtr(btNode* rPtr){
  rightPtr = rPtr;
}

void btNode::setLeftPtr(btNode* lPtr){
  leftPtr = lPtr;
}

char* btNode::getData(){
  return data;
}

btNode* btNode::getRightPtr(){
  return rightPtr;
}

btNode* btNode::getLeftPtr(){
  return leftPtr;
}
