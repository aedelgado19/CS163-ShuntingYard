//Author Allison Delgado, last updated December 6, 2020
//header file for BinaryTree node class. contains left and right ptr

class btNode {
public:

  //setters
  void setData(char* inputdata);
  void setRightPtr(btNode* rPtr);
  void setLeftPtr(btNode *lPtr);

  //getters
  char* getData();
  btNode* getRightPtr();
  btNode* getLeftPtr();

  //anatomy of a btNode:
private:
  char data[10];
  btNode *leftPtr;
  btNode *rightPtr;
};
