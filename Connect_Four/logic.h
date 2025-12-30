#ifndef LOGIC_H
#define LOGIC_H

#define BOARD_ROWS 6
#define BOARD_COLS 7


void initBoard(char board[BOARD_ROWS][BOARD_COLS]);
int dropPiece(char board[BOARD_ROWS][BOARD_COLS],int col,char piece);
int validateWin(char board[BOARD_ROWS][BOARD_COLS]);
int fullBoard(char board[BOARD_ROWS][BOARD_COLS]);

#endif