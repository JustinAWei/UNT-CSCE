/* Author: Justin Wei
 Date: 11/15/16
 Instructor: David Keathly
 Description: Uses bubble sort to sort 10 numbers in descedning order.
*/

#include <iostream>
using namespace std;

const int SIZE = 10;
void bubblesort(int arr[], int length);

int main(){
  int arr[SIZE];

  for (int i = 0; i < SIZE; i++) {
    cout << "Enter an integer: ";
    cin >> arr[i];
  }

  bubblesort(arr, SIZE);

  for(int a : arr){
    cout << a << " ";
  }
  cout << endl;

  return 0;
}

void bubblesort(int arr[], int length){
  for (int i = length - 1; i > 0; i--) {
    for(int j = 0; j < i; j++){
      //changed to sort in descending order
      if(arr[j] < arr[j+1]){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
