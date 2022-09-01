#ifndef STACKCLASS_H
#define STACKCLASS_H
#include <iostream>
using namespace std;

/*
Shane Kennedy
stack header file
*/

//Stack class
class stackClass
{
private:
  struct Node{
    char data;
    struct Node* link;
  };
  struct Node* top;

public:

  stackClass();  //Constructor
  stackClass(const stackClass& obj);  //copy Constructor
  ~stackClass();  //destructor
  stackClass& operator=(const stackClass& obj); //assingment operator

  bool isEmpty();  //check is the stack is empty
  void pop();  //return the top node of the stack
  void push(const char data);  //pushes data onto the stack
  char peek();  //return the top node of the stack without removing it

private:
  
  void copy(const stackClass& top);
  void clear();
};
#endif
