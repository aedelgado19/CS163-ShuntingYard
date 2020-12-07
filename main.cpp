/* Author: Allison Delgado
 * Last updated: December 6, 2020
 * This program uses the Shunting Yard Algorithm to
 * turn an infix expression into prefix, infix, or postfix notation
 */

#include <iostream>
#include <cstring>
#include <stack>
#include "BinaryTree.h"
using namespace std;

//ascii values for legal input options and also operations
#define ZERO 48
#define NINE 57
#define LPAR 1
#define RPAR 2
#define ADD_OR_SUB 3
#define MULT_OR_DIV 4
#define POW 5

struct Node{
  char* data;
  Node *next;
};

// stack and queue function prototypes **********
void push(Node* &headOfStack, char* inData);
char* pop(Node* &headOfStack);
char* peek(Node* &headOfStack);
bool isEmpty(Node* &head);
void displayStack(Node* &headOfStack);
void enqueue(Node*& headOfQueue, char* inData);
char* dequeue(Node*& headOfQueue);
void displayQueue(Node* &headOfQueue);

// Shunting Yard functions *********************
int checkType(char* token);
void sortToken(Node* &headOfStack, Node* &headOfQueue, int tokenType, char* token);
int checkPrecedence(char* token);

// Binary Tree functions ***********************
btNode* createTree(Node* &headOfQueue);
void visualPrint(Node* headOfQueue, int depth);
void postToIn(btNode* topOfStack);
void postToPre(btNode* topOfStack);
// *********************************************

//converts postfix to infix using recursion
void postToIn(btNode* topOfStack){
  //infix is x + y
  if(topOfStack != NULL){
    postToIn(topOfStack->getLeftPtr());
    cout << topOfStack->getData() << " ";
    postToIn(topOfStack->getRightPtr());
  }
}

//converts postfix to prefix using recursion
void postToPre(btNode* topOfStack){
  //prefix is + x y
  if(topOfStack != NULL){
    cout << topOfStack->getData() << " ";
    postToPre(topOfStack->getLeftPtr());
    postToPre(topOfStack->getRightPtr());
  }
}

//converts postfix to postfix using recursion
//seems redundant i know, but gotta use the tree
void postToPost(btNode* topOfStack){
  //postfix is x y +
  if(topOfStack != NULL){
    postToPost(topOfStack->getLeftPtr());
    postToPost(topOfStack->getRightPtr());
    cout << topOfStack->getData() << " ";
  }
}

//uses the same algorithm as my previous Heap program,
//prints a horizontal tree
void visualPrint(btNode* topOfStack, int depth){
  if(topOfStack == NULL){
    return;
  }

  //print top child (right)
  visualPrint(topOfStack->getRightPtr(), depth+1);
  
  //spacing
  for(int i = 0; i < depth; i++){
    cout << "    ";
  }
  cout << topOfStack->getData() << endl;

  //bottom child(left)
  visualPrint(topOfStack->getLeftPtr(), depth+1);
}

/*
takes in postfix queue
algorithm from https://www.geeksforgeeks.org/expression-tree/
1. if token is a number, it is pushed onto stack
2. if token is an operator, pop the top 2 values from the stack
and make them the child of the new node, push current node
*/
btNode* createTree(Node *&headOfQueue){
  stack <btNode*> *btStack = new stack<btNode*>; 
  Node *currentNode = headOfQueue;
  while(currentNode != NULL){
    //if it's a number
    if(isdigit(currentNode->data[0])){
      btNode* newnode = new btNode();
      newnode->setData(currentNode->data);
      btStack->push(newnode);
    } else { //it's  an operator
      btNode* newnode = new btNode();
      newnode->setData(currentNode->data);
      //pop first 2 nodes
      btNode* rChild = new btNode();
      rChild = btStack->top();
      btStack->pop();
      btNode* lChild = new btNode();
      lChild = btStack->top();
      btStack->pop();

      //save as children
      newnode->setRightPtr(rChild);
      newnode->setLeftPtr(lChild);
      btStack->push(newnode);
    }
    //update current node
    currentNode = currentNode->next;
  }
  
  //all that's left is top of tree
  btNode* topOfStack = btStack->top();
  btStack->pop(); //remove top
  return topOfStack;
}

//adds a new node after the last one and moves "last" to next
void enqueue(Node* &headOfQueue, char* inData){
  Node* newnode = new Node;
  Node* traverse = NULL;
  int dataSize = strlen(inData);
  newnode->data = new char[dataSize];

  //no head yet, so make head
  if(headOfQueue == NULL){
    headOfQueue = newnode;
    strcpy(newnode->data, inData);
    newnode->next = NULL;
  } else { //not making head
    traverse = headOfQueue;
    while(traverse->next != NULL){ //find end of list
      traverse = traverse->next;
    }
    //out of loop, found end
    traverse->next = newnode; //attach
    strcpy(newnode->data, inData); 
    newnode->next = NULL;
  }
}

//removes top node and makes next node to "top"
char* dequeue(Node* &headOfQueue){
  Node* temp = NULL;
  if(headOfQueue != NULL){ //theres stuff in the list
    int dataSize = strlen(headOfQueue->data); //used in line below
    char* backupData = new char[dataSize];
    temp = headOfQueue; //copy original head
    headOfQueue = temp->next; //update head
    temp->next = NULL; //disconnect chain
    strcpy(backupData, temp->data);
    delete temp;
    return backupData;
  } else {
    cout << "Queue is empty. " << endl;
  }
  return NULL;
}

//displays entire queue
void displayQueue(Node* &headOfQueue){
  if(headOfQueue != NULL){
    Node* traverse = headOfQueue;
    cout << traverse->data;
    while(traverse->next != NULL){ //traverse thru list
      traverse = traverse->next;
      cout << " " << traverse->data;
    }
  }
  cout << endl;
}

//takes in data, creates a new node, and stacks it on top of stack LL
void push(Node* &headOfStack, char* inData){
  Node* newnode = new Node;
  int dataSize = strlen(inData);
  newnode->data = new char[dataSize];

  //create new head
  if(headOfStack == NULL){
    headOfStack = newnode;
    strcpy(newnode->data, inData);
    newnode->next = NULL;
  } else { //otherwise make new node, attach its next to head
    newnode->next = headOfStack;
    newnode->data = inData;
    headOfStack = newnode;
  }
}

//used in peek to see if empty
bool isEmpty(Node *&head){
  if(head == NULL){
    return true;
  }
  else {
    return false;
  }
}

//returns top element's data
char* peek(Node *&headOfStack){
  bool empty = isEmpty(headOfStack);
  if(empty == false){ 
    return headOfStack->data;
  } else {
    cout << "Peek: Empty stack. " << endl;
  }
  return NULL;
}

//delete head of stack
char* pop(Node* &headOfStack){
  Node* temp = new Node;
  if(headOfStack != NULL){
    int dataSize = strlen(headOfStack->data); //used in line below
    char* backupData = new char[dataSize];
    temp = headOfStack; //original head
    headOfStack = headOfStack->next; //new "head"
    temp->next = NULL; //disconnect original from next
    strcpy(backupData, temp->data);
    delete(temp); //delete original head
    return backupData;
  } else {
    cout << "head of stack is null!" << endl;
  }
  return NULL;
}

//used for debug, displays entire stack
void displayStack(Node* &headOfStack){
  Node* traverse = NULL;
  int count = 1;
  cout << "Stack: ";
  if(headOfStack != NULL){
    traverse = headOfStack;
    cout << traverse->data;
    while(traverse->next != NULL){
      traverse = traverse->next;
      cout << " " << traverse->data;
      count++;
    }
  }
  cout << endl;
}

// sort token onto stack or queue based on what it is
// uses shunting yard algorithm
void sortToken(Node* &headOfStack, Node* &headOfQueue, int tokenType, char* token){
  int tokPNum = checkPrecedence(token); //the p in pNum stands for precendence
  char* discard; //used to store garbage later
  char* topDataQ = new char[100];
  char* topDataS = new char[100];
  int topTypeStack = 0;
  int topPNum = 0;
  int topTypeQueue = 0;
  if(headOfQueue != NULL){ //set up queue variables
    strcpy(topDataQ, headOfQueue->data);
    topTypeQueue = checkType(topDataQ);
  }
  if(headOfStack != NULL){ //set up stack variables
    strcpy(topDataS, headOfStack->data);
    topTypeStack = checkType(topDataS);
    topPNum = checkPrecedence(topDataS); //prec. num of stack head
  }
  
  if(isdigit(token[0])){ //if it's a number
    enqueue(headOfQueue, token);
  }
  else if(tokenType == LPAR){ //it is a left parenthesis
    push(headOfStack, token);
  }
  else if(tokenType == RPAR){ //it is a right parenthesis
    while(strcmp(peek(headOfStack), "(")){//while not left parenthesis
      enqueue(headOfQueue, pop(headOfStack));
      
    } //out of while, meaning found L Parenthesis
    discard = pop(headOfStack);
  }
  else if(tokenType == ADD_OR_SUB || tokenType == MULT_OR_DIV ||
	  tokenType == POW){ //it is an operator
    while(headOfStack != NULL && tokenType != POW &&
	  strcmp(peek(headOfStack), "(") &&
	  checkPrecedence(peek(headOfStack)) >= tokPNum){
      //pop from stack onto queue
      enqueue(headOfQueue, pop(headOfStack));
    }
    push(headOfStack, token); //push token to stack
  }
  else { //something's wrong if this else fires
    cout << "Error in sorting token, unknown token is passed." << endl;
  }
}

//checks the type of token, returns a num based on type.
//see #define 's at top
int checkType(char* token){
  if(strcmp(token, "(") == 0){
    return LPAR; 
  }
  if(strcmp(token, ")") == 0){
    return RPAR; 
  }
  if(strcmp(token, "-") == 0 || strcmp(token, "+") == 0){
    return ADD_OR_SUB; 
  }
  if(strcmp(token, "*") == 0 || strcmp(token, "/") == 0){
    return MULT_OR_DIV;
  }
  if(strcmp(token, "^") == 0){
    return POW;
  }
  return 0;
}

//checks precedence using PEMDAS (higher num = highest prec)
int checkPrecedence(char* token){
  int tokenType = checkType(token);
  if(tokenType == POW){ //highest precedence: ^
    return 3;
  }
  else if(tokenType == MULT_OR_DIV){
    return 2; //medium precendence: * and /
  }
  else if(tokenType == ADD_OR_SUB){
    return 1; //lowest precedence: + and -
  }
  return 0;
}

int main(){
  btNode* top = NULL;
  Node* headOfStack = NULL;
  Node* headOfQueue = NULL;  
  char* parsed = new char[100];
  char input[100];
  int choice = 0;
  bool valid = false;
  int tokenType = 0;

  //welcome messages
  cout << "******************" << endl;
  cout << "Welcome to Shunting Yard." << endl;
  cout << "Please enter your mathematical expression in INFIX notation. " << endl;
  cout << "Use spaces to separate each token, including parenthesis." << endl;
  cout << "Acceptable tokens: +, -, *, /, ^, ( ), and integer numbers." << endl;
  cout << "******************" << endl;
  cin.get(input, 100);
  cin.get();

  //parse input using tokenizer
  char *token = strtok(input, " ");
  while(token != NULL){
    tokenType = checkType(token);
    sortToken(headOfStack, headOfQueue, tokenType, token);
    token = strtok(NULL, " ");
  }

  //enqueue the head of stack
  while(headOfStack != NULL){
    enqueue(headOfQueue, pop(headOfStack));
  }

  //print out results using postfix and also the tree
  cout << "Postfix: ";
  displayQueue(headOfQueue);
  top = createTree(headOfQueue);
  cout << "Tree: " << endl;
  visualPrint(top, 0);

  //keep looping until they type something valid
  while(valid == false){
    cout << "Would you like to output the expression in: " << endl;
    cout << "(1) infix notation" << endl;
    cout << "(2) prefix notation" << endl;
    cout << "(3) postfix notation" << endl;
    cin >> choice;
    cin.get();
    cout << endl;
    if (choice == 1){ //infix
      cout << "infix: ";
      postToIn(top);
      cout << endl;
      valid = true;
    }
    else if (choice == 2){ //prefix
      cout << "prefix: ";
      postToPre(top);
      cout << endl;
      valid = true;
    }
    else if (choice == 3){ //postfix.. again.
      cout << "postfix: ";
      postToPost(top);
      cout << endl;
      valid = true;
    }
    else { //oops! they made a typo
      cout << "That was not a valid choice. Please try again: " << endl;
    }
  }
  return 0;
}
