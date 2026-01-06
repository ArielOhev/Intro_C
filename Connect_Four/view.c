#include "view.h"

/*
 * Function: printHeader
 * ----------------------------
 * Displays the game title.
 */

void printHeader(){
    system("cls"); 
    
    printf(BLUE "=========================================\n" RESET);
    printf(CYAN "          C O N N E C T   4      \n" RESET);
    printf(BLUE "=========================================\n" RESET);
    printf(GREEN "         made by ariel ohev\n" RESET);
    printf("\n");
}

/*
 * Function: printMenu
 * ----------------------------
 * Displays the main menu with available game options:
 * 1. PvP, 2. PvC, 3. Stats, 4. Exit.
 */
void printMenu(){
    printHeader();

    printf(BLUE "\n=== MAIN MENU ===\n" RESET);
    printf("1. Play vs Friend (2 Players)\n");
    printf("2. Play vs Computer \n");
    printf("3. Watch statistics \n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}


/*
 * Function: printBoard
 * ----------------------------
 * Visualizes the game board in the console.
 * 
 * returns: void
 */
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

/*
 * Function: printLevelsMenu
 * ----------------------------
 * Displays the difficulty selection menu for the "User vs Computer" mode.
 *
 * returns: void
 */
void printLevelsMenu(){
    printHeader();

    printf(BLUE "\n=== Choose Your Level ===\n" RESET);
    printf("1. Easy\n");
    printf("2. Hard\n");
    printf("Enter your choice: ");
}

/*
 * Function: showPlayerStats
 * ----------------------------
 * Calculates and displays the leaderboard / statistics.
 *
 * returns: void
 */
void showPlayerStats(struct Player p1, struct Player p2,struct Player pc){
    int totalGames = p1.wins + p2.wins + p1.draws+pc.wins;
    printHeader();

    printf(BLUE "\n=== LEADERBOARD ===\n" RESET);

    printf("Total Games:    %d\n", totalGames);
    printf(RED    "%-10s (X):" RESET " %d Wins\n", p1.name, p1.wins);
    printf(YELLOW "Player 2:  (O):" RESET " %d Wins\n", p2.wins);
    printf(CYAN   "%-10s    :" RESET " %d Wins\n", "Computer", pc.wins);
    printf(GREEN  "%-10s    :" RESET " %d\n", "Draws", p1.draws);

    printf(BLUE "===================\n" RESET);
}

/*
 * Function: printWinner
 * ----------------------------
 * Displays the "GAME OVER" message with the winner's name.
 */
void printWinner(struct Player p){
    printf(BLUE "*************************\n" RESET);
    if(p.isComputer)printf(" GAME OVER! " CYAN "%s" RESET " WINS! \n",p.name);
    else if(p.color=='X')printf(" GAME OVER! " RED "%s" RESET " WINS! \n",p.name);
    else if(!p.isComputer && p.color=='O')printf(" GAME OVER! " YELLOW "%s" RESET " WINS! \n",p.name);
    printf(BLUE "*************************\n" RESET);
}


