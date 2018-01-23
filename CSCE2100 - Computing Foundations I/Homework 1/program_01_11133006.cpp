/*
Name: Justin Wei
Class: CSCE 2100
Instructor: Hamid
Date: 1/30/17
*/
#include "student.h"
#include <iostream>
#include <stdio.h>

/*
Function Name: Highest GPA
Parameters: Reference to an array of students
Returns: Reference to a student object
Description: Returns a reference to the student with the highest GPA
*/
student & highest_gpa(student( & student_array)[5]);

/*
Function Name: read_student_input
Parameters: Reference to an string, string and float
Returns: nothing
Description: reads student name, id and gpa
*/
void read_student_input(string & name, string & id, float & gpa);

/*
Function Name: all_alpha
Parameters: string
Returns: boolean
Description: returns true if string is only alphabetical characters
*/
bool all_alpha(string);

/*
Function Name: all_digit
Parameters: string
Returns: boolean
Description: returns true if string is only numbers
*/
bool all_digit(string);

/*
Function Name: error_handling
Parameters: none
Returns: none
Description: resets cin fail state and clears cin stream
*/
void error_handling();

int main() {
  string name, id;
  float gpa;

  cout << "Initialzing students a, b, and c" << endl;

  student a;
  cout << "Created the following student object using constructor 1:" << endl;
  a.print();

  cout << "Input properties for student b:\n";
  read_student_input(name, id, gpa);

  student b(name, id, gpa);
  cout << "Created student object b using constructor 2:" << endl;
  b.print();

  student c(b);
  cout << "Created student object c using constructor 3:" << endl;
  c.print();

  cout << "Creating two more student objects: \n" << endl;

  read_student_input(name, id, gpa);
  student d(name, id, gpa);
  cout << "Created student object d using constructor 2:" << endl;
  d.print();

  read_student_input(name, id, gpa);
  student e(name, id, gpa);
  cout << "Created student object e using constructor 2:" << endl;
  e.print();

  //Array of 5 Students
  student student_array[5] = {a,b,c,d,e};

  int index = 0, edit_index;
  char edit_type, cont;

  //Menu to edit students
  do {
    index = 0;

    //display students
    for (student s: student_array) {
      cout << index++ + 1 << ". ";
      s.print();
    }

    cout << "Which student object would you like to edit? (1 - 5): ";

    //input student index to edit
    do {
      cin >> edit_index;
      if (cin.fail()) {
        edit_index = -1;
        error_handling();
        continue;
      }
    } while (edit_index < 1 || edit_index > 5);

    cout << "How would you like to edit the student object? \na) Input your own student information. \nb) Use another student's information\n";

    //input method of editing
    do {
      cin >> edit_type;
      if (cin.fail()) {
        edit_type = 'c';
        error_handling();
        continue;
      }
    } while (edit_type < 'a' || edit_type > 'b');

    //copy via input or copy constructor
    if (edit_type == 'a') {
      string name, id;
      float gpa;
      read_student_input(name, id, gpa);
      student_array[edit_index - 1] = student(name, id, gpa);
      cout << "Sucessfully updated!" << endl;
    } else if (edit_type == 'b') {
      int other_student_index;
      cout << "Enter the number of the student you want to copy: ";
      do {
        cin >> other_student_index;
        if (cin.fail()) {
          other_student_index = -1;
          error_handling();
          continue;
        }
      } while (other_student_index < 1 || other_student_index > 5);
      student_array[edit_index - 1] = student(student_array[other_student_index - 1]);
      cout << "Sucessfully updated!" << endl;
    }

    cout << "Here is the updated student list." << endl;
    index = 0;
    for (student s: student_array) {
      cout << index++ + 1 << ". ";
      s.print();
    }

    //input descision to continue editing
    cout << "Continue? (y/n):";
    cin >> cont;
    if (cin.fail()) {
      error_handling();
      continue;
    }
  } while (cont == 'y');

  //Find the Student with the highest GPA
  student highest_gpa_student = highest_gpa(student_array);

  //Print his/her info
  cout << "\nThe student with the highest GPA:\n";
  highest_gpa_student.print();

  return 0;
}

student & highest_gpa(student( & student_array)[5]) {
  float highest_gpa = -1;
  int student_index = 0;
  //Loop through the array and find the student with the higest GPA
  for (int i = 0; i < 5; i++) {
    if (student_array[i].get_gpa() > highest_gpa) {
      highest_gpa = student_array[i].get_gpa();
      student_index = i;
    }
  }
  return student_array[student_index];
}

void read_student_input(string & name, string & id, float & gpa) {
  do {
    cout << "Enter the name of the student:";
    cin >> name;
    if (cin.fail()) {
      name = "-1";
      error_handling();
      continue;
    }

    cout << "Enter the id of the student:";
    cin >> id;
    if (cin.fail()) {
      id = "a";
      error_handling();
      continue;
    }

    cout << "Enter the GPA of student:";
    cin >> gpa;
    if (cin.fail()) {
      gpa = -1;
      error_handling();
      continue;
    }
  } while (!all_alpha(name) || !all_digit(id) || gpa < 0 || gpa > 4);
  return;
}

bool all_alpha(string s) {
  for (char c: s) {
    if (!isalpha(c)) {
      return false;
    }
  }
  return true;
}

bool all_digit(string s) {
  for (char c: s) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

void error_handling() {
  cout << "Sorry there was an error with your input" << endl;
  cin.clear();
  cin.ignore(32676, '\n');
  return;
}
