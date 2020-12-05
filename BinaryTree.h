//header file for BinaryTree node class. contains left and right ptr

class Node {
public:
  void setData(char* inputdata);
  void setRightPtr(Node* rPtr);
  void setLeftPtr(Node *lPtr);
  char* getData();
  Node* getRightPtr();
  Node* getLeftPtr();
  
private:
  char* data;
  Node *leftPtr;
  Node *rightPtr;
};
