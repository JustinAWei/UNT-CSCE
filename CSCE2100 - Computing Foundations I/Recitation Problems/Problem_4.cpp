/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Instructor: Hamid
*/

#include <iostream>
#include <string>
using namespace std;

class Triangle{
private:
  float base, height;
public:
  Triangle() : base(0), height(0){
  }
  ~Triangle(){

  }
  void set_base(float new_base){
      base = new_base;
  }
  float get_base(){
    return base;
  }
  void set_height(float new_height){
    height = new_height;
  }
  float get_height(){
    return height;
  }
};

class Area_Calculator : public Triangle{
  float area;
public:
  Area_Calculator() : area(0){
    area = .5 * get_base() * get_height();
  }
  ~Area_Calculator(){}
  void calc_area(){
    area = .5 * get_base() * get_height();
  }
  float get_area(){
    return area;
  }
};

int main(){
  Area_Calculator t1, t2;
  t1.set_base(1);
  t1.set_height(1);
  t1.calc_area();

  t2.set_base(2);
  t2.set_height(2);
  t2.calc_area();

  cout << "Area of Triabgle with base of " << t1.get_base() << " and height of " << t1.get_height() << " is " <<  t1.get_area() << endl;
  cout << "Area of Triabgle with base of " << t2.get_base() << " and height of " << t2.get_height() << " is " <<  t2.get_area() << endl;

  return 0;
}
