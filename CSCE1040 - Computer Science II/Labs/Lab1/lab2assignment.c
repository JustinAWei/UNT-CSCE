/* Name: Justin Wei
Class: CSCE 1040
Professor: Keathly
Date: 1/23/2017
*/

#include <stdio.h>
#include <string.h>


int main(int argc, const char* argv[]){

  //file opening
  FILE *fp;
  fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("Error opening file.\n");
    return 1;
  }

  //variables
  char type, trans_type, emp_name[16], cus_name[16];
  char employees[51][16], customers[51][16];
  float bals[51];
  int emp_id, cus_id;
  float bal, trans_amnt;

  //print long string of digits
  printf("1234567890123456789012345678901234567890\n");


  //scan first character
  while(fscanf(fp, " %c", &type) != EOF){
    switch(type){

      //initialize employee with id and name
      case 'e':
        fscanf(fp,"%i %s", &emp_id, emp_name);
        strcpy(employees[emp_id], emp_name);
        break;

      //initialize customize with id, name, and bal
      case 'c':
        fscanf(fp,"%i %s %f", &cus_id, cus_name, &bal);
        strcpy(customers[cus_id], cus_name);
        bals[cus_id] = bal;
        break;

      //perform transaction and print customer, employee, transaction amount, remaining bal
      case 't':
        fscanf(fp,"%i %i %c %f", &cus_id, &emp_id, &trans_type, &trans_amnt);
        if(trans_type == 'w'){
          trans_type = '-';
          trans_amnt *= -1;
        }
        else{
          trans_type = '+';
        }
        bals[cus_id] += trans_amnt;
        printf("%s\t\t%s %c$%.2f $ %.2f\n",customers[cus_id], employees[emp_id], trans_type, trans_amnt, bals[cus_id]);
        break;
      default:
        break;
    }
  }

  return 0;
}
