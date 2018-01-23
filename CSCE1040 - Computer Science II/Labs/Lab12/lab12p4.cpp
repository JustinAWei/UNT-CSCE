/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Class: CSCE 1040
Instructor: Keathly
Description: A function to demonstrate virtual functions and polymorphism.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

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
    char *getName() {
      return name;
    }
    long GetSalary() {
      return salary;
    }
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
  int num_employees;
  cout << "How many employees would you like to create? ";
  cin >> num_employees;

  Employee* EmployeeList[num_employees];
  string types = "\na. Manager\n\tb. Officer\n\tc. Technician";

  for (int i=0; i<num_employees; i++) {
    cout << "What kind of employee do you want to ? \n" << types << endl;
    char choice;
    cin >> choice;
    switch (choice) {
      case 'a':
      {
        cout << "What is the name of the manager? ";
        char c[100];
        scanf("%s", c);
        char p[100];
        cout << "What is his/her degree? ";
        scanf("%s", p);
        long salary;
        cout << "What is his/her salary? ";
        cin >> salary;
        EmployeeList[i] = new Manager(c, salary, p);
        break;
      }
      case 'b': {
        // Officer
        cout << "What is the name of the officer? ";
        char c[100];
        scanf("%s", c);
        char p[100];
        cout << "What's his/her position? ";
        scanf("%s", p);
        long salary;
        cout << "What's his/her salary? ";
        cin >> salary;
        EmployeeList[i] = new Officer(c, salary, p);
        break;
      }
      case 'c': {
        // Technician
        cout << "What's the technician's name? ";
        char c[100];
        scanf("%s", c);
        char p[100];
        cout << "What's his/her position? ";
        scanf("%s", p);
        long salary;
        cout << "What's his/her salary? ";
        cin >> salary;
        EmployeeList[i] = new Technician(c, salary, p);
        break;
      }
      default: {
        i--;
        break;
      }
    }
  }

  while (true) {
    cout << "Choose an option:\n\ta. Make a list of employees introduced\n\tb. Search for an employee by name\n\tc. Exit the program" << endl;
    char choice;
    cin >> choice;

    switch (choice) {
      case 'a': {
        for (int i=0; i<num_employees; i++) {
          EmployeeList[i]->show_info();
        }
        break;
      }
      case 'b': {
        char name[100];
        cout << "Enter the name to search: ";
        scanf("%s", name);
        for (int i=0; i<num_employees; i++) {
          if (strcmp(name, EmployeeList[i]->getName())) {
            EmployeeList[i]->show_info();
            break;
          }
        }
        break;
      }
      case 'c': {
        cout << "Exiting...\n";
        return 0;
        break;
      }
    }
  }

  for (int i=0; i<num_employees; i++) {
    EmployeeList[i]->show_info();
  }

  return 0;
}
