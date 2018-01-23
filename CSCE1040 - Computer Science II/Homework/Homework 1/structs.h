/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE1004
Instructor: Keathly
Date: 2/10/17
Description: Header file for structures
*/

#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
using namespace std;

struct Student {
  int id;
  string name;
  Student * next;
};

struct Course {
  int id;
  string name;
  Course * next;
};

struct Grade {
  int value;
  Grade * next;
};

struct Grades {
  int size;
  Grade * head, * tail;

  Grades();
  ~Grades();
};

struct Enrollment {
  int id;
  Student * student;
  Enrollment * next;

  Course * course;
  Grades * grades;
};

struct Students {
  int size;
  Student * head, * tail;

  Students();
  ~Students();
};

struct Courses {
  int size;
  Course * head, * tail;

  Courses();
  ~Courses();
};

struct Enrollments {
  int size;
  Enrollment * head, * tail;

  Enrollments();
  ~Enrollments();
};

#endif
