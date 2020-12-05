/* Author: Allison Delgado
 * Last updated: December 5, 2020
 */

#include <iostream>
#include "BinaryTree.h"
using namespace std;

struct Node{
  char* data;
  
};

// function prototypes **********
void push();
char* pop();
char* peek();
void enqueue();
void dequeue();
// *****************************

int main(){
  char input[500];
  cout << "Welcome to Shunting Yard." << endl;
  cout << "Please enter your mathematical expression in INFIX notation. " << endl;
  cout << "Use spaces to separate each token, including parenthesis." << endl;
  cout << "Acceptable tokens: +, -, *, /, ^, ( ), and integer numbers." << endl;
  cin.get(input, 500);
  cin.get();

  
  return 0;
}
