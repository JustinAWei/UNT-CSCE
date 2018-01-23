/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Class: CSCE 1040
Instructor: Keathly
Description: A function to demonstrate virtual functions and polymorphism.
*/
#include <iostream>
#include <string.h>

using namespace std;

class Employee {
private:
  char name[20];
public:
  //constructors
  Employee(char* c) {
    strcpy(name, c);
  }

  // virtual function
  virtual void show_info() {
    cout << "Employee" << endl;
  }
  char *getName() {return name;}
};

class Manager : public Employee {
  public:
    Manager(char *c) : Employee(c) {}
    void show_info() {
      cout << "Manager: " << getName() << endl;
    }
};

class Worker : public Employee {
  public:
    Worker (char *c) : Employee(c) {}
    void show_info() {
      cout << "Worker: " << getName() << endl;
    }
};

class Officer : public Employee {
  public:
    Officer(char *c) : Employee(c) {}
    void show_info() {
      cout << "Officer: " << getName() << endl;
    }
};

class Technician : public Employee {
  public:
    Technician(char *c) : Employee(c) {}
    void show_info() {
      cout << "Technician: " << getName() << endl;
    }
};

int main() {
  Employee Rafa("Rafa");
  Manager Mario("Mario");
  Worker Anton("Anton");
  Officer Luis("Luis");
  Technician Pablo("Pablo");

  // The type of object pointed by a pointer to the base class
  // determines the function that is being called
  Employee *pe;
  cout << "\nInheritance and Polymorphism:\n" << endl;
  pe = &Rafa;
  pe->show_info();

  pe = &Mario;
  pe-> show_info();

  pe = &Anton;
  pe-> show_info();

  pe = &Luis;
  pe-> show_info();

  pe = &Pablo;
  pe-> show_info();

  cout << "Ya he terminado." << endl;
  return 0;
}
