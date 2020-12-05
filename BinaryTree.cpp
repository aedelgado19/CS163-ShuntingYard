//binary tree node class. contains left and right pointer
#include <BinaryTree.h>

void BinaryTree::setData(inputdata){
  strcpy(data, inputdata);
}

void BinaryTree::setRightPtr(Node* rPtr){
  //do this

}

void BinaryTree::setLeftPtr(Node* lPtr){
  //do this

}

char* BinaryTree::getData(){
  return data;
}

Node* BinaryTree::getRightPtr(){
  return rightPtr;
}

Node* BinaryTree::getLeftPtr(){
  return leftPtr;
}
