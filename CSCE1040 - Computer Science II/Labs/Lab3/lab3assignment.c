/*
Name: Justin Wei
Instructor: Keathly
Date: 2/9/17
Description: Use a linkedlist to attach two datasets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char   *name;
  float  balance;
  struct account *next;
};

int main()
{
	int		 listID;
  float  balance;
  char   name[20];
  struct account *list1head = NULL;
  struct account *list1tail = NULL;
	struct account *list2head = NULL;
  struct account *list2tail = NULL;
  struct account *walk = NULL;


  while(scanf("%d%s%f", &listID, name, &balance) != EOF) {
		if(listID == 1) {
			if(list1head == NULL) {
				list1head = (struct account*) malloc(sizeof(struct account));
        list1head->name = (char*) malloc(strlen(name));
        strcpy(list1head->name, name);
        list1head->balance = balance;
        list1tail = list1head;
      }
			else {
        list1tail->next = (struct account*) malloc(sizeof(struct account));
        list1tail->next->name = (char*) malloc(strlen(name));
        strcpy(list1tail->next->name, name);
        list1tail->next->balance = balance;
        list1tail = list1tail->next;
        }
		}
		else { // listID == 2
      if(list2head == NULL) {
				list2head = (struct account*) malloc(sizeof(struct account));
        list2head->name = (char*) malloc(strlen(name));
        strcpy(list2head->name, name);
        list2head->balance = balance;
        list2tail = list2head;
      }
			else {
        list2tail->next = (struct account*) malloc(sizeof(struct account));
        list2tail->next->name = (char*) malloc(strlen(name));
        strcpy(list2tail->next->name, name);
        list2tail->next->balance = balance;
        list2tail = list2tail->next;
        }
		}

  }//E HERE TO COUNT THE NODES IN EACH LIST

  printf("i");
  int len1 = 0, len2 = 0;
  walk = list1head;
  while(walk != NULL){
    len1++;
    walk = walk->next;
  }

  walk = list2head;
  while(walk != NULL){
    len2++;
    walk = walk->next;
  }

	if(len1 > len2){
    list1tail->next = list2head;
  }
  else{
    list2tail->next = list1head;
  }

	// print list1
	walk = list1head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);
    walk = walk->next;
  }
	// print list2
	printf("----------------\n");
	walk = list2head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);
    walk = walk->next;
  }

  walk = list1head;
  while(walk != NULL) {
    struct account* temp = walk;
    walk = walk->next;
    free(temp);
  }

  return 0;
}
