/*
Name: Justin Wei
Course: CSCE 1040
Instructor: Keathly
Date: 1/23/17
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: Liars
Parameters: int
Return: long
Description: Generates n liar liars
*/

long liars(int n);
int main(int argc, char *argv[]) {
  //input num of liar liars
  int n;

  printf("How many Liar-Liar numbers would you like to generate? ");
  scanf("%d", &n);

  //print scale
  printf("123456789012345678901234567890\n");
  //generate liarliars from 1 to n
  for (int i = 1; i <= n; i++) {
    //print function(n) = liarliar
    printf("liar(%2d) = %16ld\n", i, liars(i));
  }

  return 0;
}

long liars(int n) {
  //base
  if (n <= 2) {
    return -1;
  }
  else {
    return 2*(liars(n-1)+liars(n-2));
  }
}
