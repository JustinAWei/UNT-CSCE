/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE1004
Instructor: Keathly
Date: 2/10/17
Description: A gradebook system using structs and linkedlists
*/

#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "functions.h"

using namespace std;

int main() {

  //Print student info
  print_student_info();

  string cont = "y";
  int choice = -1;

  do {
    print_menu();
    do {
      cin >> choice;
      if (choice < 0 || choice > 12 || cin.fail()) {
        cout << "Enter a number between 0 and 12.";
        choice = -1;
        cin.clear();
        cin.ignore(32676, '\n');
      }
    } while (choice < 0 || choice > 12);

    switch (choice) {

      //Eixt
    case 0:
      {
        cout << "Are you sure? Everything will be destroyed. (y/n)";
        cin >> cont;
        if(cont == "y"){
          clean_up();
          return 0;
        }
        break;
      }

      //Add new course
    case 1:
      {
        Course * new_course = new Course;
        cout << "Course ID: ";
        input_integer(new_course->id);
        cout << "Course Name: ";
        cin >> new_course->name;
        add(new_course);
        break;
      }
      //Add new student
    case 2:
      {
        Student * new_student = new Student;
        cout << "Student ID: ";
        input_integer(new_student->id);
        cout << "Student Name: ";
        cin >> new_student->name;
        add(new_student);
        break;
      }
      //Add student to course
    case 3:
      {
        int course_id,
        student_id;
        cout << "Student ID: ";
        input_integer(student_id);
        cout << "Course ID: ";
        input_integer(course_id);
        add(student_id, course_id);
        break;
      }

      //add grades for student in course
    case 4:
      {
        int student_id,
        course_id,
        count;
        cout << "Student ID: ";
        input_integer(student_id);
        cout << "Course ID: ";
        input_integer(course_id);
        cout << "Amount of grades to add: ";
        input_integer(count);
        int * grades_array = new int[count];
        for (int i = 0; i < count; i++) {
          cout << "Grade #" << i << " :";
          input_integer(grades_array[i]);
        }
        add(student_id, course_id, count, grades_array);
        delete[] grades_array;
        break;
      }

      //print all grades for student in course
    case 5:
      {
        int student_id,
        course_id;
        cout << "Student ID: ";
        input_integer(student_id);
        cout << "Course ID: ";
        input_integer(course_id);
        print_grades(student_id, course_id);
        break;
      }
      //print list of all students in a course
    case 6:
      {
        int course_id;
        cout << "Course ID: ";
        input_integer(course_id);
        print_students(course_id);
        break;
      }

      //compute avg for student in a course
    case 7:
      {
        int student_id,
        course_id;
        cout << "Student ID: ";
        input_integer(student_id);
        cout << "Course ID: ";
        input_integer(course_id);
        cout << "Average: " << average(student_id, course_id) << endl;
        break;
      }

      //print list of all courses
    case 8:
      {
        print_all_courses();
        break;
      }

      //print list of all students
    case 9:
      {
        print_all_students();
        break;
      }
      //compute avg for course
    case 10:
      {
        int course_id;
        cout << "Course ID: ";
        input_integer(course_id);
        cout << "Average: " << average(course_id) << endl;
        break;
      }

      //store grade book
    case 11:
      {
        string filename;
        cout << "Filename: ";
        cin >> filename;
        store_gradebook(filename);
        break;
      }

      //load grade book
    case 12:
      {
        string filename;
        cout << "Filename: ";
        cin >> filename;
        load_gradebook(filename);
        break;
      }
      //try again if not 0-12
    default:
      continue;
    }
    do {

      cout << "continue? (y/n)";
      cin >> cont;
      if (cin.fail()) {
        cont = 'z';
        cin.clear();
        cin.ignore(32676, '\n');
      }
    } while (cont != "n" && cont != "y");

  } while (cont == "y");

  clean_up();
  return 0;
}
