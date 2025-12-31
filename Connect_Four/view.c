#include <stdio.h>
#include "view.h"
#include "logic.h"

// הגדרות צבעים (ANSI Escape Codes)
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

void welcomeMessage() {
    printf("***************************\n");
    printf(BLUE "Welcome to Connect 4!\n" RESET);
    printf("***************************\n");
}

void printMenu(){
    printf(BLUE "\n=== MAIN MENU ===\n" RESET);
    printf("1. Play vs Friend (2 Players)\n");
    printf("2. Play vs Computer (Coming Soon)\n");
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

void PrintStatistics(char *gameHistory,int playedGames){
    int count_X=0;
    int count_O=0;
    int count_D=0;
    char option;

    for(int i=0;i<playedGames;i++){
        option = gameHistory[i];

        switch (option)
        {
        case 'X':
            count_X++;
            break;
        case 'O':
            count_O++;
            break;
        case 'D':
            count_D++;
            break;
        default:
            break;
        }
    }

    if (playedGames == 0) {
        printf(BLUE "\nNo games history yet.\n" RESET);
        return;
    }

    printf(BLUE "\n=== SCOREBOARD ===\n" RESET);
    printf("Total Games: %d\n", playedGames);
    printf(RED    "RED (X):     %d\n" RESET, count_X);
    printf(YELLOW "YELLOW (O):  %d\n" RESET, count_O);
    printf(RESET  "DRAWS:       %d\n" RESET, count_D);
    printf(BLUE "==================\n" RESET);

    
}






