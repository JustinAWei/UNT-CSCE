/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Class: CSCE 1040
Instructor: Keathly
Description: A function to demonstrate virtual functions and polymorphism.
*/

#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define NUM_EMPLOYEES 6

class Employee {
private:
  char name[20];
  long salary;

public:
  //constructors
  Employee(char* c, long salary) : salary(salary) {
    strcpy(name, c);
  }
  // virtual function
  virtual void show_info() {
    cout << "Employee: " << name << endl;
    cout << "Salary: " << salary << endl;
  }
  char *getName() {return name;}
  long GetSalary() {return salary;}
};

class Manager : public Employee {
protected:
  char *degree;
public:
  Manager(char *c, long salary, char *degree) : Employee(c, salary) {
    this->degree = (char*)malloc(strlen(degree) + 1);
    strcpy(this->degree, degree);
  }
  void show_info() {
    cout << "Manager: " << getName() << endl;
    cout << "Degree: " << degree << endl;
    cout << "Salary: " << GetSalary() << endl;
  }
};

class Worker : public Employee {
  protected:
    char *position;
  public:
    Worker (char *c, long salary, char *position) : Employee(c, salary) {
      this->position = (char*)malloc(strlen(position) + 1);
      strcpy(this->position, position);
    }
    void show_info() {
      cout << "Worker: " << getName() << endl;
      cout << "Position: " << position << endl;
      cout << "Salary: " << GetSalary() << endl;
    }
};

class Officer : public Employee {
  protected:
    char *position;
  public:
    Officer(char *c, long salary, char *position) : Employee(c, salary) {
      this->position = (char*)malloc(strlen(position) + 1);
      strcpy(this->position, position);
    }
    void show_info() {
      cout << "Officer: " << getName() << endl;
      cout << "Salary: " << GetSalary() << endl;
    }
};

class Technician : public Employee {
  protected:
    char *position;
  public:
    Technician(char *c, long salary, char *position) : Employee(c, salary) {
      this->position = (char*)malloc(strlen(position) + 1);
      strcpy(this->position, position);
    }
    void show_info() {
      cout << "Technician: " << getName() << endl;
      cout << "Salary: " << GetSalary() << endl;
    }
};

int main() {

  Employee* EmployeeList[NUM_EMPLOYEES];
  EmployeeList[0] = new Manager("Carla Garcia", 35000, "Economist");
  EmployeeList[1] = new Manager ("Juan Perez", 38000, "Ingineer");
  EmployeeList[2] = new Officer("Pedro Egia", 18000, " Officer 1");
  EmployeeList[3] = new Officer ("Luisa Penia", 15000, " Officer 2");
  EmployeeList[4] = new Technician("Javier Ramos", 19500, "Welder");
  EmployeeList[5] = new Technician ("Amaia Bilbao", 12000, "Electricist");

  for (int i=0; i<NUM_EMPLOYEES; i++) {
    EmployeeList[i]->show_info();
  }

  return 0;
}
