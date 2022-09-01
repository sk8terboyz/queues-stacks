#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
/*
Header file for the Queue class
By Shane Kennedy
*/

class Queue {
private:
  void clear();  //clear method
  void copy(const Queue& que);  //copy method
  struct Node{
    int data;
    struct Node* next;
  };
  struct Node* head;  //head of queue
  struct Node* tail;  //tail of queue

public:
  Queue(); //Constructor
  Queue(const Queue& obj);  //Copy Constructor
  ~Queue();  //Destructor
  Queue& operator=(const Queue& obj);  //Assignment Operator

  bool isEmpty();  //Checks if queue is empty
  void enqueue(int element);  //Insert new element to queue
  void dequeue();  //remove element from queue
  int front();  //access front of queue

};
#endif
