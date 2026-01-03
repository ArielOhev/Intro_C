#ifndef LOGIC_H
#define LOGIC_H
#include <string.h>

#define BOARD_ROWS 6
#define BOARD_COLS 7

struct Player{
    char name[50];
    char color;
    int wins;
    int draws;
    int isComputer;
};


/*
 * Function: initBoard
 * ----------------------------
 * Initializes the game board by setting all cells to empty spaces.
 */
void initBoard(char board[BOARD_ROWS][BOARD_COLS]);
int newNumber();
int dropPiece(char board[BOARD_ROWS][BOARD_COLS],int col,char piece);
int validateWin(char board[BOARD_ROWS][BOARD_COLS]);
int fullBoard(char board[BOARD_ROWS][BOARD_COLS]);
int getComputerMove(char board[BOARD_ROWS][BOARD_COLS]);
struct Player initPlayer(char color, char* prompt);

void unDrop(char board[BOARD_ROWS][BOARD_COLS],int col);
int getBestMove(char board[BOARD_ROWS][BOARD_COLS]);

#endif