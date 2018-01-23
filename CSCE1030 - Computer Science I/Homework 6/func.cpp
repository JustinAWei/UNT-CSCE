/*
   ============================================================================
   Program Name : homework6.cpp
   Author : Justin Wei
   Instructor: David Keathley
   Course: CSCE 1030
   Date: 12/4/2016
   Description : Development of the basic working game "CSCE1030 Crush"
   ============================================================================
 */

#include "prgm.h"

void print_student_info(){

        //Print my info
        cout << "+-----------------------------------------+" << endl;
        cout << "| Computer Science and Engineering        |" << endl;
        cout << "| CSCE 1030 - Computer Science I          |" << endl;
        cout << "| Justin Wei jaw0561 JustinWei@my.unt.edu |" << endl;
        cout << "+-----------------------------------------+" << endl;

        return;
}

void print_game_intro(){
        //print the intro to the game
        cout << "-----------------------------------------------------------" <<endl;
        cout << "            W e l c o m e t o 1 0 3 0 C r u s h" <<endl;
        cout << "This program will randomly initialize your game board using" <<endl;
        cout << "a set of 6 characters (!, \", #, $, %, &) that a player will" <<endl;
        cout << "then attempt to match a combination of 3 or more characters" <<endl;
        cout << "to gain points in a finite set of moves or time duration." << endl;
        cout << "-----------------------------------------------------------" << endl;
        return;
}

void print_board(ppCandy board,stats &game_stats){

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
        cout << "Moves: " << game_stats.num_moves << "\t Score: " << game_stats.score << endl;

        return;
}

void initialize_board(ppCandy board, stats &game_stats){

        for (int row = 0; row < 9; row++) {
                for (int col = 0; col < 9; col++) {

                        //generate random characters within the range 33-38 inclusive
                        candy temp_candy = candy(rand() % 6 + 33);
                        board[row][col] = temp_candy;
                }
        }

        //display the board after its been initialized
        print_board(board,game_stats);

        return;
}

void get_location(stats &game_stats){
        string input;

        do {
                cout << "Enter location for move #" << game_stats.num_moves << " (e.g., B7): ";

                cin >> input;

                game_stats.row = input[0];
                game_stats.col = input[1]-'0';


                if(game_stats.row == 'R' && game_stats.col == 0){
                  return;
                }

                if(cin.fail()) {
                        cin.clear();
                        cin.ignore('\n',1000);
                }
        }
        while(game_stats.row < 'A' || game_stats.row > 'I' || game_stats.col < 1 || game_stats.col > 9);

        return;
}

void get_direction(stats &game_stats){
        game_stats.dir = -1;
        do {
                cout << "Enter direction (V = Vertical, H = Horizontal):";
                cin >> game_stats.dir;

                if(cin.fail()) {
                        cin.clear();
                        cin.ignore('\n', 1000);
                        cout << "Error. Try again" << endl;
                        game_stats.dir = -1;
                }
        }
        while((game_stats.dir != 'V' && game_stats.dir != 'v') && (game_stats.dir != 'H' && game_stats.dir != 'h'));

        return;
}

int match_vertical(ppCandy board, stats &game_stats){
        int score = 0;
        int cent_row = game_stats.row - 'A';
        int cent_col = game_stats.col - 1;
        int start = cent_row, end = cent_row;


        //search up
        for (int row = cent_row; row < BOARDSIZE; row++) {
                if(board[row][cent_col] == board[cent_row][cent_col]) {
                        score++;
                }
                else{
                        end = row;
                        break;
                }
        }

        //seach down
        for (int row = cent_row; row >= 0; row--) {
                if(board[row][cent_col] == board[cent_row][cent_col]) {
                        score++;
                }
                else{
                        start = row;
                        break;
                }
        }

        score--;
        //look at the middle
        if(score >= 3) {
                vertical_fill_matched(start, end, cent_col, board,game_stats);
                return score;
        }
        return 0;
}

int match_horizontal(ppCandy board, stats &game_stats){
        int score = 0;
        int cent_row = game_stats.row - 'A';
        int cent_col = game_stats.col - 1;
        int start = cent_col, end = cent_col;


        //search right
        for (int col = cent_col; col < BOARDSIZE; col++) {
                if(board[cent_row][col] == board[cent_row][cent_col]) {
                        score++;
                }
                else{
                        end = col;
                        break;
                }
        }

        //search left
        for (int col = cent_col; col >= 0; col--) {
                if(board[cent_row][col] == board[cent_row][cent_col]) {
                        score++;
                }
                else{
                        start = col;
                        break;
                }
        }

        score--;
        //look at the middle
        if(score >= 3) {
                horizontal_fill_matched(start,end, cent_row, board,game_stats);
                return score;
        }

        return 0;
}

void horizontal_fill_matched(int start, int end, int cent_row, ppCandy board,stats &game_stats){
  for (int col = start; col <= end; col++) {
    board[cent_row][col] = candy(rand()%6 + 33);
  }
  return;
}

void vertical_fill_matched(int start, int end, int cent_col, ppCandy board,stats &game_stats){
  for (int row = start; row <= end; row++) {
    board[row][cent_col] = candy(rand()%6 + 33);
  }
  return;
}

void make_move(ppCandy board, stats &game_stats){
        game_stats.num_moves++;
        int turn_score = 0;
        get_location(game_stats);

        if(game_stats.row == 'R' && game_stats.col == 0) {
                cout << "Reshuffling..." << endl;
                initialize_board(board, game_stats);
                return;
        }

        get_direction(game_stats);
        if(game_stats.dir == 'v' || game_stats.dir == 'V') {
                turn_score = match_vertical(board,game_stats);
        }
        else if(game_stats.dir == 'h' || game_stats.dir == 'H') {
                turn_score = match_horizontal(board,game_stats);
        }

        if(turn_score > 0) {
                game_stats.score += turn_score;
                cout << "Well done! +" << turn_score << " points!" << endl;
        }
        else{
                cout << "No match. Try again!" << endl;
        }
        print_board(board,game_stats);

        return;
}
