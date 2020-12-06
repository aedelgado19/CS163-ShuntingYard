/* Author: Allison DOAelgado
 * Last updated: December 5, 2020
 * This program uses the Shunting Yard Algorithm to
 * turn an infix expression into prefix, infix, or postfix notation
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
void displayStack(Node* &headOfStack);
void enqueue(Node*& headOfQueue, char* inData);
char* dequeue(Node*& headOfQueue);
void displayQueue(Node* &headOfQueue);
// helper functions ****************************
bool isEmpty(Node* &head);
char* parseInput(char* input);
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
char* parseInput(char* input){
  cout << "A" << endl;
  char *token = strtok(input, " ");
  while(token != NULL){
    cout << "B" << endl;
    token = strtok(NULL, " ");
  }
  cout << "C" << endl;
  return token;
}

int main(){
  Node* headOfStack = NULL;
  Node* headOfQueue = NULL;  
  char* parsed = new char[100];
  char input[100];
  int choice = 0;
  bool valid = false;
  cout << "Welcome to Shunting Yard." << endl;
  cout << "Please enter your mathematical expression in INFIX notation. " << endl;
  cout << "Use spaces to separate each token, including parenthesis." << endl;
  cout << "Acceptable tokens: +, -, *, /, ^, ( ), and integer numbers." << endl;
  cin.get(input, 100);
  cin.get();

  //do conversions here
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
  cout << "poop" << endl;
  strcpy(parsed, parseInput(input));
  cout << "pee" << endl;
  cout << " :) " << parsed << endl;
  return 0;
}
