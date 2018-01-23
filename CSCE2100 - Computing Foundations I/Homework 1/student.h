/*
Name: Justin Wei
Class: CSCE 2100
Instructor: Hamid
Date: 1/30/17
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

using namespace std;

class student {

  string name, id;
  float gpa; // 0 <= gpa <= 4

  public:

  //Constructors
  student(); //cons_0 ==> set default values with empty string and 0.00 as gpa
  student(string name, string id, float gpa); //cons_1
  student(const student & other_student); //cost_2

  //returns name
  string get_name() const;

  //returns id
  string get_id() const;

  //returns gpa
  float get_gpa() const;

  //modifies the name
  void set_name(string new_name);

  //modifies the id
  void set_id(string new_id);

  //modifies the gpa
  void set_gpa(float gpa);

  //prints the details
  void print();
};

#endif
