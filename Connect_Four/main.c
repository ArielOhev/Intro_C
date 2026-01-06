#include "logic.h"
#include "view.h"

void gameLoop(struct Player *p1,struct Player *p2,int level) {
    char Board[BOARD_ROWS][BOARD_COLS];
    struct Player *currP=p1;
    int column, success;
    initBoard(Board);
    
    while (1) {
        system("cls");
        printBoard(Board);
                
        // הצגת תור השחקן עם צבע מתאים
        if (currP->color=='X')printf("Player " RED "%s" RESET "'s turn, ",currP->name);
        else printf("Player " YELLOW "%s" RESET "'s turn, ",currP->name);
        
        //האם זה מחשב ומול איזה רמה אנחנו משחקים
        if(currP->isComputer){
            column= (level==2)?getBestMove(Board):getComputerMove(Board);
        }
        else column=newNumber();

        success = dropPiece(Board, column, currP->color);

        if (success == 1) {
            // בדיקת ניצחון
            if (validateWin(Board) == 1) {

                system("cls");
                printBoard(Board);
                printWinner(*currP);

                currP->wins++;
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
    printHeader();

    struct Player p1 = initPlayer('X', "Enter Your name: ");
    struct Player p2;
    struct Player pc = initPlayer('O', NULL);

    int choice;
    

    while (1)
    {
        system("cls");
        printMenu();

        // Safe input handling: prevents infinite loop if char is entered
        if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n'); 
        choice = -1; 
        }

        switch(choice){
            // --- Mode: Player vs Player ---
            case 1:
                p2 = initPlayer('O', "Enter name for Player 2 (Yellow): ");
                gameLoop(&p1,&p2,1);
                break;
            // --- Mode: Player vs Computer ---
            case 2:
                printLevelsMenu();
                scanf("%d",&choice);
                switch (choice)
                {
                case 1: //Easy
                    gameLoop(&p1,&pc,1);
                    break;
                case 2: //Hard
                    gameLoop(&p1,&pc,2);
                    break;
                
                default:
                    printf("Invalid choice, please try again.\n");
                    break;
                }
                break;

            // --- Show Statistics ---
            case 3:
                showPlayerStats(p1,p2,pc);
                system("pause");
                break;
            
            // --- Exit Game ---
            case 4:
                printf("Goodbye!\n");
                return 0; 
            default:
                printf("Invalid choice, please try again.\n");
                system("pause");
        }
    }
    
    return 0;
}

