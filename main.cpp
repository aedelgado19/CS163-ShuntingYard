/* Author: Allison Delgado
 * Last updated: December 5, 2020
 */

#include <iostream>
#include <cstring>
#include "BinaryTree.h"
using namespace std;

struct Node{
  char* data;
  Node *next;
};

// stack and queue function prototypes **********
void push(Node* &headOfStack, char* inData);
char* pop(Node* &headOfStack);
char* peek(Node* &headOfStack);
void display(Node* &headOfStack);
void enqueue(Node* headOfQueue, char* inData);
void dequeue();
// helper functions ****************************
bool isEmpty(Node* &head);
// *********************************************

//adds a new node after the last one and moves "last" to next
void enqueue(Node* &headOfQueue, char* inData){
    
}

//removes top node and moves next node to "top"
void dequeue(Node* &headOfQueue){
    
}

//takes in data, creates a new node, and stacks it on top of stack LL
void push(Node* &headOfStack, char* inData){
  Node* newnode = new Node;
  if(headOfStack == NULL){
    headOfStack = newnode;
    newnode->data = inData;
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
    int dataSize = strlen(headOfStack->data);
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
void display(Node* &headOfStack){
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

int main(){
  Node* headOfStack = NULL;
  Node* headOfQueue = NULL;  
  char input[100];
  cout << "Welcome to Shunting Yard." << endl; /*
  cout << "Please enter your mathematical expression in INFIX notation. " << endl;
  cout << "Use spaces to separate each token, including parenthesis." << endl;
  cout << "Acceptable tokens: +, -, *, /, ^, ( ), and integer numbers." << endl;
  cin.get(input, 100);
  cin.get();
  */

  return 0;
}
