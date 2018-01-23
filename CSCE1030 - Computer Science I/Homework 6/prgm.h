#ifndef PRGM_H
#define PRGM_H

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

//Streams
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

//candy enum type
enum candy {
        EXCLAM = '!',
        HASHTAG = '#',
        PERCENTAGE = '%',
        DOUBLEQUOTE = '"',
        DOLLARSIGN = '$',
        AMPERSAND = '*',
};

//statistics of the game
struct stats {
        char row, dir;
        int col, num_moves, score;
};


//typedefs
typedef candy* pCandy;
typedef pCandy* ppCandy;

//constants
const int BOARDSIZE = 9;
const int MAXMOVES = 12;
const int NUMENUMS = 6;


//function headers

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
   Function : print game intro
   Parameters : none
   Return : nothing
   Description : prints the introduction message to the game
   ============================================================================
 */
void print_game_intro();

/*
   ============================================================================
   Function : initialize_board
   Parameters : reference to a 9x9 array of candy enums
   Return : nothing
   Description : randomly fills the array with candy enums
   ============================================================================
 */
void initialize_board(ppCandy board, stats &game_stats);

/*
   ============================================================================
   Function : print_board
   Parameters : reference to a 9x9 array of candy enums
   Return : nothing
   Description : displays the contents of the 9x9 board
   ============================================================================
 */
void print_board(ppCandy board, stats &game_stats);

/*
   ============================================================================
   Function : make move
   Parameters : none
   Return : none
   Description : executes each turn
   ============================================================================
 */
void make_match(ppCandy board, stats &game_stats);

/*
   ============================================================================
   Function : get_location
   Parameters : none
   Return : none
   Description : gets input for location
   ============================================================================
 */
void get_location(stats &game_stats);

/*
   ============================================================================
   Function : get_direction
   Parameters : none
   Return : none
   Description : gets input for direction
   ============================================================================
 */
void get_direction(stats &game_stats);

/*
   ============================================================================
   Function : match_vertical
   Parameters : candy 2d array
   Return : an integer representing the score of this turn
   Description : matches adjacent similar candies vertically
   ============================================================================
 */
int match_vertical(ppCandy board,stats &game_stats);

/*
   ============================================================================
   Function : match_horizontal
   Parameters : candy 2d array
   Return : an integer representing the score of this turn
   Description : matches adjacent similar candies horizontally
   ============================================================================
 */
int match_horizontal(ppCandy board,stats &game_stats);

/*
   ============================================================================
   Function : make move
   Parameters : candy 2d array
   Return : none
   Description: executes the functions required for the user to make a move
   ============================================================================
 */
void make_move(ppCandy board,stats &game_stats);

/*
   ============================================================================
   Function : horizontal fill matched
   Parameters : start and end col index, the row index, and the board
   Return : none
   Description: replaces matched symbols with randomly generated ones
   ============================================================================
 */
void horizontal_fill_matched(int start, int end, int cent_row, ppCandy board,stats &game_stats);

/*
   ============================================================================
   Function : vert fill matched
   Parameters : start and end row index, the col index, and the board
   Return : none
   Description: replaces matched symbols with randomly generated ones
   ============================================================================
 */
void vertical_fill_matched(int start, int end, int cent_col, ppCandy board,stats &game_stats);



#endif
