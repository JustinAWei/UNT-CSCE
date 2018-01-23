/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 1040
Instructor: Keathly
Description: A program to interact with a 2d array
*/

#include <iostream>
#include <string>

using namespace std;
/*
Name: Print
Parameters:
  array of pointers for the dynamically allocated 2d matrix,
  two ints for the dimensions of the array.
Returns: None
Description: Prints the array
*/
void print(int* arr[], int N, int M);

/*
Name: Sum
Parameters:
  array of pointers for the dynamically allocated 2d matrix,
  two ints for the dimensions of the array.
Returns: None
Description: Prints the sum of all the numbers in the array
*/
void sum(int* arr[], int N, int M);

/*
Name: upper half
Parameters:
  array of pointers for the dynamically allocated 2d matrix,
  two ints for the dimensions of the array.
Returns: None
Description: Prints the upper half of the array given it is a square
*/

void upper_half(int* arr[], int N, int M);
/*
Name: Middle Column
Parameters:
  array of pointers for the dynamically allocated 2d matrix,
  two ints for the dimensions of the array.
Returns: None
Description: Prints the middle column of the array given it has an odd number of column
*/
void middle_column(int* arr[], int N, int M);

/*
Name: middle row
Parameters:
  array of pointers for the dynamically allocated 2d matrix,
  two ints for the dimensions of the array.
Returns: None
Description: Prints the middle row of the array given it has an odd number of rows
*/
void middle_row(int* arr[], int N, int M);

int main() {
  string menu = "1. Print the matrix\n2. Sum all of the elements\n3. Show the upper half\n4. Show middle row\n5. Show middle column\n";

  int N, M;
  cin >> N >> M;

  int** arr = new int*[N];
  for(int i = 0; i <N; i++)
    arr[i] = new int[M];

  //input the matrix
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  char cont = 'a';
  do {
    cont = 'a';
    int choice = -1;
    do {
      cout << menu;
      cout << "\nWhat would you like to do?\n";
      cin >> choice;
    } while (choice < 1 || choice > 5);

    switch(choice) {
      case 1:
        print(arr,N,M);
        break;
      case 2:
        sum(arr,N,M);
        break;
      case 3:
        upper_half(arr, N, M);
        break;
      case 4:
        middle_row(arr,N,M);
        break;
      case 5:
        middle_column(arr,N,M);
        break;
      default:
        break;
    }

    cout << "Continue? (y/n) ";
    cin >> cont;
  } while(cont == 'y');

  for(int i = 0; i <N; i++)
    delete[] arr[i];
  delete[] arr;
  return 0;
}

void print(int* arr[], int N, int M){
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return;
}

void sum(int* arr[], int N, int M){
  int sum = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      sum += arr[i][j];
    }
  }
  cout << "SUM: " << sum << endl;
}

void upper_half(int* arr[], int N, int M) {
  if (N == M) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if (j >= i) {
          cout << arr[i][j] << " ";
        } else {
          cout << "  ";
        }
      }
      cout << endl;
    }
    return;
  } else {
    cout << "Matrix is not a square!\n";
  }
}

void middle_row(int* arr[], int N, int M){
  if (N % 2 == 1) {
    for(int j = 0; j < M; j++) {
      cout << arr[N/2][j] << " ";
    }
    cout << endl;
    return;
  } else {
    cout << "Number of rows is not odd!\n";
  }
}

void middle_column(int* arr[], int N, int M) {
  if (M % 2 == 1) {
    for(int j = 0; j < N; j++) {
      cout << arr[j][M/2] << " ";
    }
    cout << endl;
    return;
  } else {
    cout << "Number of column is not odd!\n";
  }
}
