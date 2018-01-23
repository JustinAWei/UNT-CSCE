/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Class: CSCE 1040
Instructor: Keathly
Description: A function to demonstrate virtual functions and polymorphism.
*/

#include <iostream>

using namespace std;

class Employee {
  protected: double sal; //salary base
  public: Employee(double s) {
    sal = s;
  }
  virtual double Payment() {
    return sal;
  }
  void prt() {
    cout << "Salary=" << Payment() << endl;
  }
};


class Manager: public Employee {
  double inc;
  public: Manager(double s, double i): Employee(s) {
    inc = i;
  }
  double Payment() {
    return sal * inc;
  }
};

int main() {
  Employee e1(1500);
  Manager m1(1500, 1.5);
  cout << "Exercise about inheritance and polymorphism" << endl;
  e1.prt();
  m1.prt();
  return 0;
}
