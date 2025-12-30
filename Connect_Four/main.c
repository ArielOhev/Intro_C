#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include "view.h"


// הגדרות צבעים (ANSI Escape Codes)
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"


void gameLoop() {
    char Board[BOARD_ROWS][BOARD_COLS];
    char currentPlayer = 'X';
    int column, success;
    
    initBoard(Board);
    
    while (1) {
        system("cls"); // ניקוי מסך (בלינוקס/מק: system("clear"))
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
                printf("\n" BLUE "*************************\n");
                if (currentPlayer == 'X')
                    printf(" GAME OVER! " RED "RED" RESET " WINS! \n");
                else
                    printf(" GAME OVER! " YELLOW "YELLOW" RESET " WINS! \n");
                printf(BLUE "*************************\n" RESET);
                system("pause"); // נותן למשתמש לראות את הניצחון לפני החזרה לתפריט
                break;
            }
            // בדיקת תיקו
            if (fullBoard(Board) == 1) {
                system("cls");
                printBoard(Board);
                printf("It's a Draw!\n");
                system("pause");
                break;
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
    gameLoop();
    return 0;
}

