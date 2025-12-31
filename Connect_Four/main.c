#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include "view.h"


// הגדרות צבעים (ANSI Escape Codes)
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"


char gameLoop() {
    char Board[BOARD_ROWS][BOARD_COLS];
    char currentPlayer = 'X';
    int column, success;
    
    initBoard(Board);
    
    while (1) {
        system("cls"); 
        printBoard(Board);
        
        // הצגת תור השחקן עם צבע מתאים
        if (currentPlayer == 'X')
            printf("Player " RED "RED" RESET "'s turn: ");
        else
            printf("Player " YELLOW "YELLOW" RESET "'s turn: ");
            
        column = newNumber();
        success = dropPiece(Board, column, currentPlayer);

        if (success == 1) {
            // בדיקת ניצחון
            if (validateWin(Board) == 1) {
                system("cls");
                printBoard(Board);
                printf("\n" BLUE "*************************\n" RESET);
                if (currentPlayer == 'X')
                    printf(" GAME OVER! " RED "RED" RESET " WINS! \n");                
                else
                    printf(" GAME OVER! " YELLOW "YELLOW" RESET " WINS! \n");
                    
                printf(BLUE "*************************\n" RESET);
                system("pause");
                return currentPlayer;
            }
            // בדיקת תיקו
            if (fullBoard(Board) == 1) {
                system("cls");
                printBoard(Board);
                printf("It's a Draw!\n");
                system("pause");
                return 'D';
            }
            // החלפת תור
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Column is full! Try again.\n");
            system("pause");
        }
    }
}

int main(){
    welcomeMessage();
    int choice;
    
    char *gameHistory=NULL;
    int playedGames=0;
    char winner;

    while (1)
    {
        system("cls");
        printMenu();
        scanf("%d",&choice);

        switch(choice){
            case 1:
                winner= gameLoop();
                updateStatistics(&gameHistory,&playedGames,winner);
                break;
            case 2:
                printf("Computer mode is under construction...\n");
                // כאן בעתיד נקרא לפונקציה gameLoopVsComputer();
                system("pause");
                break;
            case 3:
                PrintStatistics(gameHistory,playedGames);
                system("pause");
                break;

            case 4:
                free(gameHistory);
                printf("Goodbye!\n");
                return 0; // יציאה מהתוכנית
            default:
                printf("Invalid choice, please try again.\n");

        }
    }
    
    return 0;
}

