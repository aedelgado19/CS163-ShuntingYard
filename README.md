# CS163-ShuntingYard

Why are we doing this?:  Trees are often used in computer science.  This program will also take advantage of a stack, which will be used to create the expression trees. Finally, we'll use a stack and queue for the Shunting Yard algorithm.

BUILD A STACK USING A LINKED LIST. You don't need a separate class for this, but you DO need the push(), pop(), and peek() functions.

BUILD A QUEUE USING A LINKED LIST. You don't need a separate class for this, but you DO need the enqueue() and dequeue() functions.

Both of these data structures are useful for the Shunting Yard algorithm.

You might need a similar stack for building your tree, too.

BUILD A BINARY TREE NODE CLASS WITH A LEFT AND RIGHT POINTER. (This is very similar to the Node class for linked list, except it has a data value, left pointer, and right pointer.)

Overview:  Take a mathematical expression containing the four basic arithmetic expressions, power (represented as a carat, '^'), integer numbers, and parentheses. You may use spaces between each token, but make sure you state have a printout that states the format you expect at the beginning. Translate it into postfix notation using the shunting yard algorithm.

Then take in the postfix notation and create an expression tree. Allow the user to output the expression as infix, prefix, or postfix notation, and use the tree to print that out. (Note that infix will lose the parentheses; this is fine.)

Interface:  Your program should read a mathematical expression entered with infix notation, using spaces between each token. It will then output the postfix expression. You should then be able to output infix, prefix, or postfix notation, which is a recursive print from the expression tree.

Points: 

10 points creating a stack properly

5 points creating a queue properly

10 points for properly working shunting yard algorithm

10 points for creating the expression tree

5 points for correct output of prefix, infix, and postfix.

10 points for commenting. Seriously. 
