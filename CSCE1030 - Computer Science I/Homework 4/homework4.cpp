
/*
============================================================================
Program Name : homework4.cpp
Author : Justin Wei
Instructor: David Keathley
Course: CSCE 1030
Date: 11/11/2016
Description : The program takes a string and a key and encrypt or decryps it.
It then writes it into a file specified by the user.
============================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

//The length of the key
const int key_length = 5;

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
Function : process
Parameters : infile stream object to handle the input file, outfile stream
object to handle the output file, a boolean to determine whether to encrypt or
decrypt
Return : nothing
Description : Processes the input and output file to take a message and either
encrypt or decrypt it using a 5-letter key. Writes the result to the output file.
============================================================================
*/
void process(ifstream& fin, ofstream& fout, bool is_encrypting);

int main(){

  //char for the user's choice on encryption or decryption
  char choice;

  //boolean to represent the choice of encrypting or decrypting
  bool is_encrypting;

  //string to hold the filenames of the input and output files.
  string filename;

  //print my info
  print_student_info();

  //Determine whether we're encrypting or decrypting
  do{
    cout << "Encrypting or Decrypting?" << endl;
    cin >> choice;

    //handle input stream failures
    if(cin.fail()){
      cin.clear();
      cin.ignore(1000, '\n');
      choice = 0;
    }
  }
  while(!(choice == 'e' || choice == 'E' ||choice == 'D' ||choice == 'd'));

  //set the boolean to the corresponding choice
  if(choice == 'e' || choice == 'E'){
    is_encrypting = true;
  }
  else if(choice == 'D' ||choice == 'd'){
    is_encrypting == false;
  }

  //prompt for input filename
  cout<<"Enter the input filename: ";
  cin >> filename;
  ifstream fin;

  //ifstream.open() needs a c-style char array
  fin.open(filename.c_str());

  //terminate if theres an error opening the file
  if(fin.fail()){
    cout << "There was an error opening the input file.\n";
    exit(1);
  }

  //prompt for output filename
  cout << "Enter the output filename: ";
  cin >> filename;
  ofstream fout;

  //ofstream.open() needs a c-style char array
  fout.open(filename.c_str());

  //terminate if theres an error opening the file
  if(fout.fail()){
    cout << "There was an error opening the output file.\n";
    exit(1);
  }

  //If there are no errors, then process the files and continue with the encryption.
  process(fin, fout, is_encrypting);

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

void process(ifstream& fin, ofstream& fout, bool is_encrypting){

  //string key to hold the key
  string key;
  char text;
  //integer to keep track of the loop through the key
  int key_place = 0;

  //get input for the key
  cout << "Enter the 5-letter key to encrypt or decrypt the file: ";
  cin >> key;

  //get every character in the file
  while(fin.get(text)){

    //if its not a blank
    if(!(isblank(text) || text == '\n')){

      //if its a letter
      if(isalpha(text)){

        //if its uppercase
        if(isupper(text)){

          //if we're encrypting
          if(is_encrypting){
            //encrypt the capital letter
            text = (text + toupper(key[key_place])) % 26 + 'A';
          }
          else{
            //decrypt the capital letter
            text = (26 + text - toupper(key[key_place])) % 26 + 'A';
          }
        }
      else{
        if(is_encrypting){
          //encrypt the lowercase letter
          text = (toupper(text) + toupper(key[key_place])) % 26 + 'a';
        }
        //encrypt the lowercase letter
        else{
          text = (26 + toupper(text) - toupper(key[key_place])) % 26 + 'a';
        }
      }
    }
      //if a letter was changed, move to the next letter of the key
      key_place++;
      if (key_place == key_length) {
        //if we're at the end of the key, go back to the begining
        key_place = 0;
      }
    }

    //write the letter to the file.
    //note that if the letter is blank, no action is performed and the space is
    //just written
    fout.put(text);
  }

  return;
}
