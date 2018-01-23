/*
Name: Justin Wei
Course: CSCE 2100
Instructor: Hamid
Date: 3/22/2017
*/
#include "lfsr.h"
#include <string>
#include <bitset>
#include <iostream>

using namespace std;

lfsr::lfsr(unsigned int x) {
  num_taps = 0;
  seed = x;
  cur = seed;
}

int* lfsr::get_numbers(){
  return numbers;
}

void lfsr::print() {
  cout << "printing lfsr numbers\nseed: " << seed << "\t" << convert(seed) << endl;
  for(int i = 1; i < 20; i++) {
    cout << numbers[i] << "\t";
    cout << convert(numbers[i]) << endl;
  }
  cout << endl;
}

void lfsr::random_number_generator() {
  cout << "generating random numbers...\n";
  for(int i = 0; i < 20; i++) {
    numbers[i] = cur;
    unsigned int num = cur >> taps[0];
    for(int i = 1; i < num_taps; i++) {
      num ^= (cur >> taps[i]);
      num &= 1;
    }
    cur = (cur >> 1) | (num << 7);
  }
}

int lfsr::convert(string s) {
  return static_cast<unsigned int>(bitset<8>(s).to_ulong());
}

string lfsr::convert(int d) {
  return (bitset<8>(d).to_string());
}

void lfsr::insert_tap(int tap){
  if(num_taps >= 8) {
    cout << "too many taps! (max: 8)\n";
    return;
  } else {
    taps[num_taps++] = tap;
  }
}
