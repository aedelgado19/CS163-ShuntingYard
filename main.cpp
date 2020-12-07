/* Author: Allison DOAelgado
 * Last updated: December 5, 2020
 * This program uses the Shunting Yard Algorithm to
 * turn an infix expression into prefix, infix, or postfix notation
 */

#include <iostream>
#include <cstring>
#include "BinaryTree.h"
using namespace std;

//ascii values for legal input options
#define ZERO 48
#define NINE 57

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
// *********************************************

//adds a new node after the last one and moves "last" to next
void enqueue(Node* &headOfQueue, char* inData){
  Node* newnode = new Node;
  Node* traverse = NULL;
  int dataSize = strlen(inData);
  newnode->data = new char[dataSize];
  if(headOfQueue == NULL){ //no head yet, so make head
    headOfQueue = newnode;
    strcpy(newnode->data, inData);
    newnode->next = NULL;
  } else {
    traverse = headOfQueue;
    while(traverse->next != NULL){
      traverse = traverse->next;
    }
    //out of loop, found end
    traverse->next = newnode;
    strcpy(newnode->data, inData);
    newnode->next = NULL;
  }
}

//removes top node and makes next node to "top"
char* dequeue(Node* &headOfQueue){
  Node* temp = NULL;
  if(headOfQueue != NULL){
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

//used for debug, displays entire queue
void displayQueue(Node* &headOfQueue){
  int count = 1;
  if(headOfQueue != NULL){
    Node* traverse = headOfQueue;
    cout << "head: " << traverse->data << endl;
    while(traverse->next != NULL){
      traverse = traverse->next;
      cout << count << ": " << traverse->data << endl; 
      count++;
    }
  }
}

//takes in data, creates a new node, and stacks it on top of stack LL
void push(Node* &headOfStack, char* inData){
  Node* newnode = new Node;
  int dataSize = strlen(inData);
  newnode->data = new char[dataSize];
  if(headOfStack == NULL){
    headOfStack = newnode;
    strcpy(newnode->data, inData);
    newnode->next = NULL;
  } else {
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

//returns top element
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
    delete(temp);
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
  if(headOfStack != NULL){
    traverse = headOfStack;
    cout << "head: " << traverse->data << endl;
    while(traverse->next != NULL){
      traverse = traverse->next;
      cout << count << ": " << traverse->data << endl;
      count++;
    }
  }
}
/*
TODO:
might wanna replace the numbers in sortToken with constants but k

 */



// sort token onto stack or queue based on what it is
// uses shunting yard algorithm
void sortToken(Node* &headOfStack, Node* &headOfQueue, int tokenType, char* token){
  int tokPNum = checkPrecedence(token); //the p in pNum stands for precendence
  char* topDataQ = new char[100];
  strcpy(topDataQ, headOfQueue->data);
  char* topDataS = new char[100];
  strcpy(topDataS, headOfStack->data);
  int topTypeQueue = checkType(topDataQ);
  int topTypeStack = checkType(topDataS);
  int topPNum = checkPrecedence(topDataS); //precedence num of stack head
  char* data = new char[100];
  if(isdigit(token[0])){
    enqueue(headOfQueue, token);
  }
  else if(tokenType == 1){ //it is a left parenthesis
    push(headOfStack, token);
  }
  else if(tokenType == 2){ //it is a right parenthesis
    while(topTypeStack != 1){ //while not left parenthesis
      data = pop(headOfStack);
      enqueue(headOfQueue, data);
    } //out of while, meaning found L Parenthesis
    data = pop(headOfQueue);
    //TODO: MOVE DATA INTO GARBAGE STACK
    if(headOfStack != NULL){
      while(headOfStack != NULL){
	data = pop(headOfStack);
	enqueue(headOfQueue, data);
      }
    }
  }
  else if(tokenType == 3 || tokenType == 4){ //it is an operator
    while((headOfQueue != NULL && topPNum > tokPNum) ||
	  (headOfQueue != NULL && topPNum == tokPNum &&
	   topTypeQueue != 1)) { 
      //pop from stack onto queue
      data = pop(headOfStack);
      enqueue(headOfQueue, data);
      push(headOfStack, token);
    }
  }
  else { //something's wrong if this else fires
    cout << "Error in sorting token, unknown token is passed." << endl;
  }
}

//checks the type of token, returns a num based on type.
//this num can also be used to show precedence
// 1 = ( , 2 = ) , 3 = + or -, 4 = / or *, 5 = ^
int checkType(char* token){
  if(strcmp(token, "(") == 0){
    return 1; // this is a left parenthesis
  }
  if(strcmp(token, ")") == 0){
    return 2; //this is a right parenthesis
  }
  if(strcmp(token, "-") == 0 || strcmp(token, "+") == 0){
    return 3; //this is a + or -
  }
  if(strcmp(token, "*") == 0 || strcmp(token, "/") == 0){
    return 4; //this is a / or *
  }
  if(strcmp(token, "^") == 0){
    return 5; //this is a ^
  }
  return 0;
}

int checkPrecendence(char* token){
  int tokenType = checkType(token);
  if(tokenType == 5){ //highest precedence: ^
    return 3;
  }
  else if(tokenType == 4){
    return 2; //medium precendence: * and /
  }
  else if(tokenType == 3){
    return 1; //lowest precedence: + and -
  }
  return 0;
}

int main(){
  Node* headOfStack = NULL;
  Node* headOfQueue = NULL;  
  char* parsed = new char[100];
  char input[100];
  int choice = 0;
  bool valid = false;
  int tokenType = 0;
  cout << "Welcome to Shunting Yard." << endl;
  cout << "Please enter your mathematical expression in INFIX notation. " << endl;
  cout << "Use spaces to separate each token, including parenthesis." << endl;
  cout << "Acceptable tokens: +, -, *, /, ^, ( ), and integer numbers." << endl;
  cin.get(input, 100);
  cin.get();

  //parse input
  char *token = strtok(input, " ");
  while(token != NULL){
    token = strtok(NULL, " ");
    tokenType = checkType(token);
    sortToken(headOfStack, headOfQueue, tokenType, token);
  }
  
  
  //outputting choices
  while(valid == false){
    cout << "Would you like to output the expression in: " << endl;
    cout << "(1) infix notation" << endl;
    cout << "(2) prefix notation" << endl;
    cout << "(3) postfix notation" << endl;
    cin >> choice;
    cin.get();
    if (choice == 1){ //infix

    }
    else if (choice == 2){ //prefix

    }
    else if (choice == 3){ //postfix

    }
    else {
      cout << "That was not a valid choice. Please try again: " << endl;
    }
  }

  return 0;
}
