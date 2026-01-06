#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_ROWS 6
#define BOARD_COLS 7

// הגדרות צבעים (ANSI Escape Codes)
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"


struct Player{
    char name[50];
    char color;
    int wins;
    int draws;
    int isComputer;
};

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