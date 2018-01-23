/*
Name: Justin Wei
Course: CSCE 2100
Instructor: Hamid
Date: 3/22/2017
*/
#ifndef LFSR
#define LFSR

#include <string>

using namespace std;

class lfsr{
private:
  unsigned int seed;
  unsigned int cur;
  int numbers[20], taps[8], num_taps;

public:
  //constructor
  lfsr(unsigned int);

  //generates 20 random numbers
  void random_number_generator();

  //prints the randomly generated numbers
  void print();

  //specifies which blocks are taps
  void insert_tap(int);

  //converts a binary representation to decimal
  int convert(string s);

  //converts a decimal to binary string
  string convert(int);

  //returns the randomly generated numbers in an array
  int* get_numbers();
};

#endif
