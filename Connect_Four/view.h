#ifndef VIEW_H
#define VIEW_H
#include "logic.h" 

void welcomeMessage();
void printBoard(char board[BOARD_ROWS][BOARD_COLS]);
int newNumber();
void printMenu();
void printLevelsMenu();
void showPlayerStats(struct Player p1, struct Player p2,struct Player pc);


#endif