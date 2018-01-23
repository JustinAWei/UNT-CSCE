/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Hamid
01. implement a class function in the cqueue class to print all the elements from thequeue (without dequeueing them!) [10 points]
02. implement a class function in the cqueue class to count the current size of the queue(if you have inserted 5 elements and dequeued 3, the current size is 2, initially the queue size is 0) [10 points]
03. implement a class function for dequeue class to dequeue all the elements from the queue (print each element as you delete them) [10 points]


04. modify the while loop in the main function to take the input from user while enqueuing new value.  [05 Points]
Add 3 test cases for each completed task with your submitted code.

Bonus:
Pick any 2 out of Task 01, 02, and 03. Each carries 10 points. If you can complete all three (01, 02, 03), the third one will be  bonus point and will be added to any of the previous recitation quiz of your choice (mention which one to pick!).


*/
#include<iostream>
#include "cqueue.h"

using namespace std;


int main()
{

  cqueue q;
  char c = 'c'; //enter 's' to end
  int j = 20;

  while(c != 's')
   {
    cout << "enter 'e' to enqueue "<< endl << "enter 'd' to dequeue" << endl << "enter 's' to stop"<< endl;
    cin >> c;
     if (c == 'e') {
       cout << "Which value would you like to input? ";
       cin >> j;
      q.enqueue(j);

     }
     else if (c == 'd'){
       int v = q.dequeue();
       cout << "Current Value: "<< v << endl;
      }
     else {
       cout << "There is currently " << q.size() << " values in the queue.\n\n";
       q.print();
       cout << "There is currently " << q.size() << " values in the queue.\n";
       q.clear();
       cout << "There is currently " << q.size() << " values in the queue.\n";
       break;
     }
   }



 return 0;
}
