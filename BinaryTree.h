//header file for BinaryTree node class. contains left and right ptr

class btNode {
public:
  void setData(char* inputdata);
  void setRightPtr(btNode* rPtr);
  void setLeftPtr(btNode *lPtr);
  char* getData();
  btNode* getRightPtr();
  btNode* getLeftPtr();

private:
  char* data;
  btNode *leftPtr;
  btNode *rightPtr;
};
