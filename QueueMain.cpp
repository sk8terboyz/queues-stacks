#include <iostream>
#include "Queue.h"
using namespace std;

/*
Shane Kennedy
Run through a service queue representing a supermarket check out line
*/


int main()
{

  Queue que;

  cout << "Enter a value of x for the interval of time:" << endl;
  int interval;
  cin >> interval;

  int customer = 0;
  int startTime = (rand()% interval + 1);
  int serviceTime = (rand()% interval + 1) + startTime;
  int arrivalTime = (rand()% interval + 1);
  int maxCustomers = 0;
  int inQueue = 0;
  int backup = 0;
  int waitTime = 0;
  int exitCustomer = 1;
  int maxWait = 0;

  for(int minutes = startTime; minutes < 720; minutes++)
  {
    //arrival of a customer
    if(arrivalTime == minutes)
    {
      customer++;
      cout << "Customer " << customer << " arrived at " << minutes << endl;
      que.enqueue(minutes);
      inQueue++;
      backup = inQueue - 1;
      arrivalTime = (rand()%interval + 1) + minutes;
      if(backup == 0)
        serviceTime = (rand()%interval + 1) + minutes;
      if(serviceTime == 0)
        serviceTime = (rand()%interval + 1) + minutes;
    }
    //departure of a customer
    if(serviceTime == minutes)
    {
      cout << "Customer " << exitCustomer << " left at " << minutes << endl;
      exitCustomer++;
      waitTime = minutes - que.front();
      que.dequeue();
      inQueue--;
      backup = inQueue - 1;

      //check if backup line is empty
      if(!que.isEmpty())
      {
        serviceTime = (rand()%interval + 1) + minutes;
      }
    }

    //set max customers backed up
    if(backup > maxCustomers)
    {
      maxCustomers = backup;
    }

    //set max waiting time of a customer
    if(waitTime > maxWait)
    {
      maxWait = waitTime;
    }
  }

  cout << "The maximum number of customers in the queue at any point was " << maxCustomers << endl;
  cout << "The longest wait time a customer had was " << maxWait << endl;

  return 0;
}
