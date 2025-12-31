#ifndef VIEW_H
#define VIEW_H

#include "logic.h" 

void welcomeMessage();
void printBoard(char board[BOARD_ROWS][BOARD_COLS]);
void PrintStatistics(char *gameHistory,int playedGames);
int newNumber();
void printMenu();

#endif