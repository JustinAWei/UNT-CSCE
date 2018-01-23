/*
Name: Justin Wei
Class: CSCE 2100
Instructor: Hamid
Date: 1/30/17
*/
#include "student.h"

using namespace std;

student::student(): name(""), id(""), gpa(0.00) {}
 //cons_0 ==> set default values with empty string and 0.00 as gpa

student::student(string name, string id, float gpa) {
  set_name(name);
  set_id(id);
  set_gpa(gpa);
} //cons_1

student::student(const student & other_student) {
  set_name(other_student.get_name());
  set_id(other_student.get_id());
  set_gpa(other_student.get_gpa());
} //cost_2

string student::get_name() const {
  return name;
}

string student::get_id() const {
  return id;
}

float student::get_gpa() const {
  return gpa;
}

void student::set_name(string new_name) {
  name = new_name;
}

void student::set_id(string new_id) {
  id = new_id;
}

void student::set_gpa(float new_gpa) {
  gpa = new_gpa;
}

void student::print(){
  cout << "Name: " << get_name() << "   ID: " << get_id();
  printf("   GPA: %.2f\n", get_gpa());
}
