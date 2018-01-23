/*
Name: Justin Wei
Instructor: Keathly
Date: 1/30/17
Description: Reads a list of students and computes each student's mean, the overall
average, and the min, median, and max
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"
#include <string.h>

struct classStats {
  float mean, min, max, median;
  char * name;
};

int main(int argc, char * argv[]) {
  struct classStats stats;
  stats.mean = 0;

  //file input
  FILE * ifp;
  ifp = fopen(argv[1], "r");

  //file input error
  if (ifp == NULL) {
    fprintf(stderr, "Can't open input file!\n");
    exit(1);
  }

  //scan the class
  fscanf(ifp, "%*s");
  student* students[19];
  for (int i = 0; i < 19; i++) {
    char first[256], last[256];

    //Allocate space for each student
    students[i] = (student *) malloc(sizeof(student));

    //scan the line
    fscanf(ifp, "%s %s %i %i %i", first, last, & students[i] -> exam1, & students[i] -> exam2, & students[i] -> exam3);

    //copy string into first and last because they're only char pointers
    students[i] -> first = malloc(strlen(first));
    students[i] -> last = malloc(strlen(last));
    strcpy(students[i] -> first, first);
    strcpy(students[i] -> last, last);

    //calculate mean
    students[i] -> mean = (students[i] -> exam1 + students[i] -> exam2 + students[i] -> exam3) / 3.0;

    //add to total mean
    stats.mean += students[i] -> mean;
  }

  //bubble sort the students
  bubble(students, 19);

  //set min, max, median, mean
  stats.min = students[0] -> mean;
  stats.max = students[18] -> mean;
  stats.median = students[9] -> mean;
  stats.mean /= 19.0;

  //scale
  printf("123456789012345678901234567890123456789012345678901234567890\n");

  //print stats
  printf("CSCE1040 MEAN:  %.2f MIN:  %.2f MAX:  %.2f MEDIAN:  %.2f\n", stats.mean, stats.min, stats.max, stats.median);

  for (int i = 0; i < 19; i++) {
    //print each student's stats
    printf("%12s%12s%7.2f\n", students[i] -> first, students[i] -> last, students[i] -> mean);

    //free up allocated memory
    free(students[i] -> last);
    free(students[i] -> first);
    free(students[i]);
  }
  return 0;
}
