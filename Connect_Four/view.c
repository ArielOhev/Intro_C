#include <stdio.h>
#include "view.h"
#include "logic.h"

// הגדרות צבעים (ANSI Escape Codes)
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

void welcomeMessage() {
    printf("***************************\n");
    printf(BLUE "Welcome to Connect 4!\n" RESET);
    printf("***************************\n");
}

void printMenu(){
    printf(BLUE "\n=== MAIN MENU ===\n" RESET);
    printf("1. Play vs Friend (2 Players)\n");
    printf("2. Play vs Computer \n");
    printf("3. Watch statistics \n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int newNumber(){
    int num;
    printf("Enter a Number:\n");
    scanf("%d",&num);    
    while (num<1 || num>7)
    {
        printf("Enter Number again\n");
        scanf("%d",&num);
    }
    return num-1;
}

void printBoard(char board[BOARD_ROWS][BOARD_COLS]) {
    printf("\n");
    for (int i = 0; i < BOARD_ROWS; i++) {
        printf(BLUE "|" RESET); 
        for (int j = 0; j < BOARD_COLS; j++) {
            char piece = board[i][j];            
            if (piece == 'X') {
                printf(" " RED "X" RESET " "); // איקס אדום
            } 
            else if (piece == 'O') {
                printf(" " YELLOW "O" RESET " "); // עיגול צהוב
            } 
            else {
                printf("   "); // תא ריק
            }       
            printf(BLUE "|" RESET); // קו מפריד כחול 
        }
        printf("\n");
    }
    printf("-----------------------------\n");
    printf("  1   2   3   4   5   6   7\n\n");
}

void printLevelsMenu(){
    printf(BLUE "\n=== Choose Your Level ===\n" RESET);
    printf("1. Easy\n");
    printf("2. Hard\n");
    printf("Enter your choice: ");
}

void showPlayerStats(struct Player p1, struct Player p2,struct Player pc){
    int totalGames = p1.wins + p2.wins + p1.draws+pc.wins;

    printf(BLUE "\n=== LEADERBOARD ===\n" RESET);

    printf("Total Games:    %d\n", totalGames);
    printf(RED    "%-10s (X):" RESET " %d Wins\n", p1.name, p1.wins);
    printf(YELLOW "%-10s (O):" RESET " %d Wins\n", p2.name, p2.wins);
    printf(CYAN   "%-10s    :" RESET " %d Wins\n", "Computer", pc.wins);
    printf(GREEN  "%-10s    :" RESET " %d\n", "Draws", p1.draws);

    printf(BLUE "===================\n" RESET);
}




