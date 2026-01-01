#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic.h"
#include "view.h"


// הגדרות צבעים (ANSI Escape Codes)
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"






void gameLoop(struct Player *p1,struct Player *p2) {
    char Board[BOARD_ROWS][BOARD_COLS];
    struct Player *currP=p1;

    int column, success;
    
    initBoard(Board);
    
    while (1) {
        system("cls"); 
        printBoard(Board);
        
        // הצגת תור השחקן עם צבע מתאים
        if (currP->color=='X')
            printf("Player " RED "RED" RESET "'s turn: ");
        else
            printf("Player " YELLOW "YELLOW" RESET "'s turn: ");
            
        column = (currP->isComputer) ? getComputerMove(Board):newNumber();
        success = dropPiece(Board, column, currP->color);

        if (success == 1) {
            // בדיקת ניצחון
            if (validateWin(Board) == 1) {
                system("cls");
                printBoard(Board);
                printf("\n" BLUE "*************************\n" RESET);
                if(currP->isComputer){
                    printf(" GAME OVER! " CYAN "%s" RESET " WINS! \n",currP->name);
                    currP->wins++; 
                }
                if (currP->color=='X'){
                    printf(" GAME OVER! " RED "%s" RESET " WINS! \n",currP->name);
                    currP->wins++; 
                }               
                if(!currP->isComputer && currP->color=='O'){
                    printf(" GAME OVER! " YELLOW "%s" RESET " WINS! \n",currP->name);
                    currP->wins++;
                }
                    
                printf(BLUE "*************************\n" RESET);
                system("pause");
                return;
            }
            // בדיקת תיקו
            if (fullBoard(Board) == 1) {
                system("cls");
                printBoard(Board);
                printf("It's a Draw!\n");
                system("pause");
                p1->draws++;
                p2->draws++;
                return;
            }
            // החלפת תור
            currP = currP==p1 ? p2 :p1;
        } else {
            printf("Column is full! Try again.\n");
            system("pause");
        }
    }
}

int main(){
    system("cls");
    welcomeMessage();

    struct Player p1 = initPlayer('X', "Enter name for Player 1 (Red): ");
    struct Player p2 = initPlayer('O', "Enter name for Player 2 (Yellow): ");
    struct Player pc = initPlayer('O', NULL);

    int choice;
    

    while (1)
    {
        system("cls");
        printMenu();
        scanf("%d",&choice);

        switch(choice){
            case 1:
                gameLoop(&p1,&p2);
                break;
            case 2:
                printLevelsMenu();
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    gameLoop(&p1,&pc);
                    break;
                case 2:
                    printf("Now Working right now\n");
                
                default:
                    break;
                }
                system("pause");
                break;
            case 3:
                system("cls");
                showPlayerStats(p1,p2,pc);
                system("pause");
                break;

            case 4:
                printf("Goodbye!\n");
                return 0; 
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}

