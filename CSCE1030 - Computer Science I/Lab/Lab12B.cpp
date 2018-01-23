/* Author: Justin Wei
 Date: 11/15/16
 Instructor: David Keathly
 Description: Displays the best and worst running times
*/

#include <iostream>
#include <algorithm>
using namespace std;

int find_distance(int i);

int main(){
  int i,j;
  int distance[4];
  double data[4][3];

  for (i = 0; i < 4; i++) {
    distance[i] = find_distance(i);
    cout << "\nEnter your 3 best runing times for " << distance[i] << " m\n";

    for (j = 0; j < 3; j++) {
      cout << "enter a time (in seconds): ";
      cin >> data[i][j];

    }
  }
  cout << "Here are your 3 best times: ";
  for (int i = 0; i < 4; i++) {
    cout << "\nDistance :" << distance[i] << " m\n";

    //set the min and max time to the first element
    double min_time = data[i][0], max_time = data[i][0];
    for (j = 0; j < 3; j++) {

      //compare the min and max times to each element and changing them according
      min_time = min(min_time, data[i][j]);
      max_time = max(max_time, data[i][j]);
    }
    cout << "Fastest Time: " << min_time << "\tSlowest Time: " << max_time;
    cout << endl;
  }

  return 0;
}

int find_distance(int i)
{
  switch(i)
  {
    case 0:
      return 100;
      break;
    case 1:
      return 150;
      break;
    case 2:
      return 200;
      break;

    default:
      return 400;
  }
}
