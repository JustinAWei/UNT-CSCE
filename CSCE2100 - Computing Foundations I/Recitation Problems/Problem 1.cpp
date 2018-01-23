/*
Name: Justin Wei
Instructor: Hamid
Date: 1/27/17

Define a class in C++ with the following properties:
a. Class name “circle”
b. Access attributes of the class is “public”
c. Two members of the class “radius” and “area”

In your main function
a. Define two radius
b. Calculate the area
c. Show the output for two radius
*/

#include <iostream>

using namespace std;

class circle{
public:
  //Two public members
  float radius, area;

  circle(float r) : radius(r){
    //calculate the area
    area = radius * radius * 3.14159;
  }
};

int main(){

  //define two radii
  float r1 = 1.00;
  float r2 = 2.50;

  //use circle class to calculate area
  circle c1(r1);
  circle c2(r2);

  //print area
  cout << "Area of circle with radius " << c1.radius << " is " << c1.area << "." << endl;
  cout << "Area of circle with radius " << c2.radius << " is " << c2.area << "." << endl;
  return 0;
}
