#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student {
  char name[69], major[43];
  long id_number;
  float GPA;
};

char *rev(char* s){
  int len = strlen(s);
  char* ret = (char*)malloc(sizeof(s));
  for(int i = 0; i < len; i++){
    ret[i] = s[len-1-i];
  }
  return ret;
}

long fib(int n) {
  if(n <= 1) {
    return 1;
  }
  else {
    return fib(n-1) + fib(n-2);
  }
}

int is_prime(int n){
  if (n == 1) {
    return 0;
  }
  for(int i = 2; i < n; i++) {
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}

int is_fib_prime(int n) {
  return is_prime(fib(n));
}

int main() {
  int val = 0;
  do{
    printf("Enter a value between 1 and 25: ");
    scanf("%d",&val);
  } while (val < 1 || val > 25);
  int n_fib = fib(val);
  int prime = is_prime(n_fib);
  printf("The %dth fibonacci number is %d.\n",val,n_fib);
  if(prime){
    printf("It is prime.");

  }
  else{
    printf("It is not prime.");
  }
  return 0;
}
