/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Hamid


I WOULD LIKE BONUX ON RECITATION 1
*/

#include "cqueue.h"
#include <iostream>

using namespace std;

cqueue :: cqueue()
{
   front = rear = -1;
}

void cqueue :: enqueue(int x)
{
   if ((rear+1) % 10 == front)
     {
      cout << "The queue is full"<< endl;
      return;
     }

   else
    {
     rear = (rear + 1) % 10;
     q[rear] = x;
     if (front == -1)
        front = 0;
    }

}

int cqueue :: dequeue ()
{
   if ((front == rear) && (rear == -1)) {
	cout << "The queue is empty!"<< endl;
	return -1;
	}

   else
     {
       int x = q[front];
       if(front == rear)
         { front = rear = -1;}
       else
         front = (front + 1) % 10;
      return x;
     }

}

void cqueue :: print(){
  if(size() <= 0) {
    cout << "Empty.\n";
  }
  for(int i = front; i <= rear; i++) {
    cout << q[i];
  }
}

int cqueue :: size() {

  int size = (rear - front);
  if (size < 0) {
    size *= -1;
    size += 1;
    return size;
  } else {
    size +=1;
    return size;
  }
}

void cqueue :: clear() {
  int x = dequeue();
  while(x != -1) {
    cout << x << " ";
    x = dequeue();
  }
}
