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

#ifndef cqueue_H
#define cqueue_H

class cqueue
{
  int q[10];
  int front;
  int rear;

  public:

     cqueue();
     void enqueue(int);
     int dequeue();
     void print();
     int size();
     void clear();
};

#endif
