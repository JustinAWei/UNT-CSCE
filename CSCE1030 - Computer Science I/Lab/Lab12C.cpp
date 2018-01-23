/* Author: Justin Wei
 Date: 11/15/16
 Instructor: David Keathly
 Description: compares the lengths of two c-strings
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[11], str2[12];
    int length1, length2;
    cout << "Enter the word \"Programming\" at the prompt: ";

    cin.getline(str2, 12, '\n');

    length1 = strlen(str1);
    length2 = strlen(str2);

    cout << "They have the same length, but are they the same?"<< endl;

    if (length1 == length2) {
        cout << "The two C-strings are the same."<< endl;
    }
    else {
        cout << "The two C-strings are NOT the same."<< endl;
    }
    return 0;
}
