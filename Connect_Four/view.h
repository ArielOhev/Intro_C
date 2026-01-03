#ifndef VIEW_H
#define VIEW_H
#include "logic.h" 

void printHeader();
void printBoard(char board[BOARD_ROWS][BOARD_COLS]);
void printMenu();
void printLevelsMenu();
void printWinner(struct Player p);
void showPlayerStats(struct Player p1, struct Player p2,struct Player pc);


#endif