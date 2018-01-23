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

int main(){
        stats game_stats;
        game_stats.num_moves = game_stats.score = 0;
        //seed the random number generator with the current time
        srand (time(NULL));

        //print my info
        print_student_info();

        //initialize the candy board array
        ppCandy board = new pCandy[BOARDSIZE];
        for (int row = 0; row < BOARDSIZE; row++) {
                board[row] = new candy[BOARDSIZE];
        }

        //initialize the board with candy enums
        //initializeboard automatically calls print_board and

        print_game_intro();
        initialize_board(board, game_stats);

        for (int move_num = 1; move_num <= MAXMOVES; move_num++) {
                make_move(board, game_stats);
        }

        //Game End Message
        cout << "Congratulations! Your score was "
             << game_stats.score << " in " << game_stats.num_moves << " moves!" << endl;

        //Cleanup
        for (int row = 0; row < BOARDSIZE; row++) {
                delete[] board[row];
        }
        delete[] board;

        return 0;
}
