/* Author: Allison Delgado
 * Last updated: December 5, 2020
 */

#include <iostream>
<<<<<<< HEAD
#include <cstring>
=======
>>>>>>> 9280c3826c56a0d53fa681a923db7745b6b94c18
#include "BinaryTree.h"
using namespace std;

struct Node{
  char* data;
  Node *next;
};

// stack and queue function prototypes **********
<<<<<<< HEAD
void push(Node* &headOfStack, char* inData);
char* pop(Node* &headOfStack);
char* peek(Node* &headOfStack);
void enqueue(Node* headOfQueue, char* inData);
=======
void push(Node* &headOfStack, char* data);
void pop(Node* &headOfStack);
char* peek(Node* &headOfStack);
void display();
void enqueue();
>>>>>>> 9280c3826c56a0d53fa681a923db7745b6b94c18
void dequeue();
// helper functions ****************************
bool isEmpty(Node* &head);
// *********************************************
<<<<<<< HEAD

//adds a new node after the last one and moves "last" to next
void enqueue(Node* &headOfQueue, char* inData){
    
}

//removes top node and moves next node to "top"
void dequeue(Node* &headOfQueue){
    
}

//takes in data, creates a new node, and stacks it on top of stack LL
void push(Node* &headOfStack, char* inData){
  Node* newnode = NULL;
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
    cout << "Peek: not an empty stack!" << endl;
    return headOfStack->data;
  } else {
    cout << "Peek: Empty stack. " << endl;
  }
  cout << "Peek: returning null." << endl;
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
    cout << "Pop: deleted head" << endl;
    return backupData;
  } else {
    cout << "Pop: head of stack is null" << endl;
  }
  return NULL;
}

=======

//takes in data, creates a new node, and stacks it on top of stack LL
void push(Node* &headOfStack, char* data){
  //NOTE: headOfStack is never set so this will seg fault (it's null rn)  
  Node *temp = new Node;
  Node *traverse = headOfStack;
  temp->data = data;
  while(traverse->next != NULL){
    traverse = traverse->next;
  }
  //out of while loop, found end of LLL
  traverse->next = temp;
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
    cout << "Peek: not an empty stack!" << endl;
    return headOfStack->data;
  }
  else{
    cout << "Peek: Empty stack. " << endl;
  }
  cout << "Peek: returning null." << endl;
  return NULL;
}

void pop(Node* &headOfStack){
  Node* temp = new Node;
  if(headOfStack != NULL){
    temp = headOfStack;
    headOfStack = headOfStack->next;
    temp->next = NULL;
    delete(temp);
    cout << "Pop: deleted head" << endl;
  } else {
    cout << "Pop: head of stack is null" << endl;
  }
}

>>>>>>> 9280c3826c56a0d53fa681a923db7745b6b94c18
int main(){
  Node* headOfStack = NULL;
  Node* headOfQueue = NULL;
  
  char input[100];
  cout << "Welcome to Shunting Yard." << endl;
  cout << "Please enter your mathematical expression in INFIX notation. " << endl;
  cout << "Use spaces to separate each token, including parenthesis." << endl;
  cout << "Acceptable tokens: +, -, *, /, ^, ( ), and integer numbers." << endl;
  cin.get(input, 100);
  cin.get();

  return 0;
}
