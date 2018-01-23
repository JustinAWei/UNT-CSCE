
/*
============================================================================
Program Name : homework5.cpp
Author : Justin Wei
Instructor: David Keathley
Course: CSCE 1030
Date: 11/23/2016
Description : This progrom implement the beginings of a game, "1030 Crush"
============================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;



/*
============================================================================
Function : printstudentinfo
Parameters : none
Return : nothing
Description : Displays the student info
============================================================================
*/
void print_student_info();

/*
============================================================================
Function : initialize_board
Parameters : reference to a 9x9 array of candy enums
Return : nothing
Description : randomly fills the array with candy enums
============================================================================
*/
void initialize_board(candy (&board)[9][9]);

/*
============================================================================
Function : print_board
Parameters : reference to a 9x9 array of candy enums
Return : nothing
Description : displays the contents of the 9x9 board
============================================================================
*/
void print_board(candy (&board)[9][9]);


int main(){

  //seed the random number generator with the current time
  srand (time(NULL));


  //print my info
  print_student_info();

  //print the intro to the game
  cout << "-----------------------------------------------------------" <<endl;
  cout << "W e l c o m e t o 1 0 3 0 C r u s h" <<endl;
  cout << "This program will randomly initialize your game board using" <<endl;
  cout << "a set of 6 characters (!, \", #, $, %, &) that a player will" <<endl;
  cout << "then attempt to match a combination of 3 or more characters" <<endl;
  cout << "to gain points in a finite set of moves or time duration." << endl;
  cout << "-----------------------------------------------------------" << endl;

  //initialize the candy board array
  candy board[9][9];

  //initialize the board with candy enums
  //initializeboard automatically calls printboard
  initialize_board(board);

  return 0;
}

void print_student_info(){

    //Print my info
    cout << "+-----------------------------------------+" << endl;
    cout << "| Computer Science and Engineering        |" << endl;
    cout << "| CSCE 1030 - Computer Science I          |" << endl;
    cout << "| Justin Wei jaw0561 JustinWei@my.unt.edu |" << endl;
    cout << "+-----------------------------------------+" << endl;

    return;
}

void print_board(candy (&board)[9][9]){

  cout << "     ";
  //print the column numbers
  for (int n = 1; n <= 9; n++) {
    cout << n << " ";
  }

  cout << endl << "   +--------------------+" << endl;


  for (int row = 0; row < 9; row++) {

    //print the row letter
    cout << " " << char(row + 65) << " | ";

    for (int col = 0; col < 9; col++) {

      //print the candy enums
      cout << char((board[row][col])) << " ";
    }
    cout << " | " << endl;
  }
  cout << "   +--------------------+" << endl;

  //print the game statistics
  cout << "Moves: " << 0 << "\t Score: " << 0 << endl;

  return;
}

void initialize_board(candy (&board)[9][9]){
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {

      //generate random characters within the range 33-38 inclusive
      candy temp_candy = candy(rand() % 6 + 33);
      board[row][col] = temp_candy;
    }
  }

  //display the board after its been initialized
  print_board(board);

  return;
}
