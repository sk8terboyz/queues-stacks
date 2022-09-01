#include <iostream>
#include "Queue.h"
using namespace std;

/*
Shane Kennedy
Queue class to create, access, and alter queues
*/

/*
Constructor
*/
Queue::Queue()
{
  Node* head = NULL;
  Node* tail = NULL;
}

/*
Copy Constructor
*/
Queue::Queue(const Queue& que)
{
  copy(que);
}

/*
Inserts new element into queue
*/
void Queue::enqueue(int element)
{
  struct Node* temp = new Node;

  if(!temp)
  {
    cout << "Heap Overflow" << endl;
    exit(1);
  }

  if(head == NULL)
  {
    temp->data = element;
    temp->next = nullptr;
    head = temp;
    tail = temp;
  }

  temp->data = element;
  temp->next = head;
  head = temp;

}

/*
removes value within queue
*/
void Queue::dequeue()
{
  struct Node* temp;

  if(head == NULL)
  {
    cout << "The queue is empty" << endl;
    exit(1);
  }

  temp = head;
  head = head->next;
  delete temp;
}

/*
Checks if queue is empty
*/
bool Queue::isEmpty()
{
  return head == NULL;
}

/*
returns head value of queue
*/
int Queue::front()
{
  return head->data;
}

/*
copy que into a new que
*/
void Queue::copy(const Queue& que)
{
  struct Node* temp = que.head;
  this->head = temp;
  this->tail = temp;
  while(temp != NULL)
  {
    this->tail = temp;
    this->tail->next = temp;
    temp = temp->next;
  }
}

/*
Clears the queue
*/
void Queue::clear()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

/*
Assignemnt operator
*/
Queue& Queue::operator=(const Queue& obj)
{
  if(this != &obj)
  {
    clear();
    copy(obj);
  }
  return *this;
}

/*
Destructor
*/
Queue::~Queue()
{
  clear();
}
