#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;
/*
Shane Kennedy
Main class for stack to check C++ programs for balancing symbols
*/

int main(int argc, char **argv)
{

  if(argc < 2)
  {
    cout << "Usage: " << argv[0] << " C++ program" << endl;
    exit(1);
  }

  string infile = argv[1];
  ifstream stream(infile);
  if(!stream.fail())
    cout<<infile<<" could not be opened."<<endl;
  else
  {
    string temp;
    int line = 1;
    bool exitFlag = true;
    bool commentFlag = false;
    while(stream.good() && exitFlag != 1) {
      getline(file, temp, '\n');

      for(int counter = 0; counter < temp.length() && exitFlag; counter++)
      {
        if((temp[counter] == '[' || temp[counter] == '{' || temp[counter] == '(') && !commentFlag)
        {
          stack.push(temp[counter]);
        }
        if(temp[counter] == '/' && temp[counter + 1] == '/' && !commentFlag)
        {
          commentFlag = true;
        }
        if(temp[counter] == '/' && temp[counter + 1] == '*' && !commentFlag)
        {
          commentFlag = true;
        }
        if(temp[counter] == '*' && temp[counter + 1] == '/')
        {
          if(commentFlag)
          {
            commentFlag = false;
          }
          //output case 1
          else if(!commentFlag)
          {
            cout << temp[counter] << temp[counter + 1] << " does not match " << temp[counter] << " at line " << line << "." << endl;
            exitFlag = false;
          }
          else
          {
            stack.pop();
          }
        }
        else if(temp[counter] == ']' && commentFlag)
        {
          //output case 3
          if(stack.isEmpty())
          {
            cout << temp[counter] << " on line " << line << " has no matching opening symbol." << endl;
            exitFlag = false;
          }
          //output case 1
          else if(stack.peek() != '[')
          {
            cout << stack.peek() << " does not match " << temp[counter] << " at line " << line << "." << endl;
            exitFlag = false;
          }
          else
          {
            stack.pop();
          }
        }
        else if(temp[counter] == '}')
        {
          //output case 3
          if(stack.isEmpty())
          {
            cout << temp[counter] << " on line " << line << " has no matching opening symbol." << endl;
            exitFlag = false;
          }
          //output case 1
          else if(stack.peek() != '{')
          {
            cout << stack.peek() << " does not match " << temp[counter] << " at line " << line << "." << endl;
            exitFlag = false;
          }
        }
        else if(temp[counter] == ')')
        {
          //output case 3
          if(stack.isEmpty())
          {
            cout << temp[counter] << " on line " << line << " has no matching opening symbol." << endl;
            exitFlag = false;
          }
          //output case 1
          else if(stack.peek() != ')')
          {
            cout << stack.peek() << " does not match " << temp[counter] << " at line " << line << "." << endl;
            exitFlag = false;
          }
        }
      }
      line++;
    }
    //output case 2
    if(!stack.isEmpty() && !exitFlag)
    {
      cout << "End of program reach with unmatch " << stack.peek() << "." << endl;
    }
    //output case 4
    else if(stack.isEmpty() && !exitFlag)
    {
      cout << "All symbols correctly balanced." << endl;
    }
  }
  stream.close();
  return 0;
}
