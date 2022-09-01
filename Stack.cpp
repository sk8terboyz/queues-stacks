#include <iostream>
#include "Stack.h"
using namespace std;

/*
This stack file sorts linked lists as a stack using nodes
Created by Shane Kennedy
*/

struct Node
{
  char data;
  struct Node* link;
};

struct Node* top;

/*
Constructor
*/
stackClass::stackClass()
{
  Node* top = NULL;
}

/*
copy Constructor
*/
stackClass::stackClass(const stackClass& obj)
{
  copy(obj);
}

/*
Assignment operator
*/
stackClass& stackClass::operator=(const stackClass& obj)
{
  if(this != &obj)
  {
    clear();
    copy(obj);
  }
  return *this;
}

/*
Check if the stack is empty
*/
bool stackClass::isEmpty()
{
  return top == NULL;
}

/*
Pop off the top node value
*/
void stackClass::pop()
{
  struct Node* temp;

  if(top == NULL)
  {
    cout << "stack is empty" << endl;
    exit(1);
  }
  else
  {
    temp = top;
    top = top->link;
    temp->link = NULL;
    delete temp;
  }
}

/*
Pushes a new data value onto the stack
*/
void stackClass::push(char input)
{
  struct Node* temp;

  if(!temp)
  {
    cout << "Heap Overflow" << endl;
    exit(1);
  }

  temp->data = input;

  temp->link = top;

  top = temp;
}

/*
View the top node
*/
char stackClass::peek()
{
  if(!isEmpty())
    return top->data;
  else
    exit(1);
}

/*
clear the stack of all values
*/
void stackClass::clear()
{
  struct Node* temp;
  while(top != NULL){
    temp = top;
    top = top->link;
    temp->link = NULL;
    delete temp;
  }
}

/*
copy the top node
*/
void stackClass::copy(const stackClass& obj)
{
  struct Node* other = obj->top;
  if(other != NULL)
  {
    this->top->data = other->data;
    this->top->link = NULL;
    this->tail = top;
    other = other->link;
    while(other != NULL)
    {
      tail->data = other->data;
      tail->link = NULL;
      other = other->link;
    }
  }
}

/*
Destructor
*/
stackClass::~stackClass()
{
  clear();
}
