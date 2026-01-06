#include "logic.h"

/*
 * Function: newNumber
 * ----------------------------
 * Prompts the user to enter a column number (1-7).
 * 
 * returns: The valid column index (0-6).
 */

int newNumber(){
    int num,result;
    printf("Enter a Number:\n");
    result=scanf("%d",&num);   
    
    while(getchar() != '\n');
    while (result != 1 || num<1 || num>7)
    {
        printf("Enter Number again\n");
        scanf("%d",&num);

        while(getchar() != '\n');
    }
    return num-1;
}

/*
 * Function: initBoard
 * ----------------------------
 * Initializes the game board by setting all cells to empty spaces.
 */
void initBoard(char board[BOARD_ROWS][BOARD_COLS]){
    for(int i=0;i<BOARD_ROWS;i++){
        for(int j=0;j<BOARD_COLS;j++){
            board[i][j]=' ';
        }
    }
}

/*
 * Function: dropPiece
 * ----------------------------
 * Attempts to place a player's piece in the specified column.
 * The piece will fall to the lowest available row in that column.
 *
 * board: The game board.
 * col: The column index (0-6) chosen by the player.
 * piece: The character representing the player ('X' or 'O').
 *
 * returns: 1 if the move was successful, 0 if the column is full.
 */
int dropPiece(char board[BOARD_ROWS][BOARD_COLS],int col,char piece){
    for(int i=BOARD_ROWS-1;i>=0;i--){
        if(board[i][col]==' '){
            board[i][col]=piece;
            return 1;
        }
    }
    return 0;
}

/*
 * Function: validateWin
 * ----------------------------
 * Checks the entire board to see if there is a sequence of 4 identical pieces.
 * returns: 1 if a winning sequence is found, 0 otherwise.
 */
int validateWin(char board[BOARD_ROWS][BOARD_COLS]){
    //Option 1 - בדיקה לאורך
    for(int i=0; i<BOARD_COLS; i++){
        for(int j=0; j<BOARD_ROWS-3; j++){
            char Current = board[j][i]; 
            if(Current != ' ' &&
               board[j+1][i] == Current &&
               board[j+2][i] == Current &&
               board[j+3][i] == Current){
                return 1;
            }
        }
    }

    // Option 2: בדיקה לרוחב (Horizontal) 
    for(int i=0;i<BOARD_ROWS;i++){
        for(int j=0;j<BOARD_COLS-3;j++){
            char Current = board[i][j];
            if(Current != ' ' &&
               board[i][j+1] == Current &&
               board[i][j+2] == Current &&
               board[i][j+3] == Current){
                return 1;
            }

        }
    }

    // Option 3: אלכסון יורד
    for(int i=0;i<BOARD_ROWS-3;i++){
        for(int j=0;j<BOARD_COLS-3;j++){
            char Current = board[i][j];
            if(Current != ' ' &&
               board[i+1][j+1] == Current &&
               board[i+2][j+2] == Current &&
               board[i+3][j+3] == Current){
                return 1;
            }

        }
    }
    // Option 4: אלכסון עולה
    for(int i=3;i<BOARD_ROWS;i++){
        for(int j=0;j<=BOARD_COLS-3;j++){
            char Current = board[i][j];
            if(Current != ' ' &&
               board[i-1][j+1] == Current &&
               board[i-2][j+2] == Current &&
               board[i-3][j+3] == Current){
                return 1;
            }

        }
    }


    return 0;
}

/*
 * Function: fullBoard
 * ----------------------------
 * Checks if the game board is completely full (indicating a draw).
 * This is usually done by checking if the top row is full.
 * 
 * returns: 1 if the board is full (Draw), 0 if there are still empty spots.
 */
int fullBoard(char board[BOARD_ROWS][BOARD_COLS]){
    for(int j=0;j<BOARD_COLS;j++){
        if(board[0][j]==' '){
            return 0;
        }
    }
    return 1;
}

/*
 * Function: getComputerMove
 * ----------------------------
 * Calculates the best move for the computer player.
 * Uses an algorithm based by random (Easy mode).
 *
 * board: The current state of the game board.
 *
 * returns: The column index (0-6) where the computer decides to play.
 */
int getComputerMove(char board[BOARD_ROWS][BOARD_COLS]){
    int col=-1;
    col=(rand()%7);
    while (board[0][col]!=' ')
    {
        col=(rand()%7);
    }

    return col;
}

/*
 * Function: initPlayer
 * ----------------------------
 * Initializes a Player struct with a specific color and asks for the user's name.
 *
 * returns: A generic Player struct containing the name and color.
 */
struct Player initPlayer(char color, char* prompt){
    struct Player p;

    p.color=color;
    p.wins=0;
    p.draws=0;
    p.isComputer=0;
    printf("\n");
    if (prompt != NULL) {
        printf("%s", prompt);
        scanf("%s", p.name);
    } else {
        strcpy(p.name, "Computer");
        p.isComputer=1;
    }

    return p;
}

/**
 * Function: unDrop
 * ----------------
 * Removes the top-most piece from a specific column.
 * This is a helper function used for the function "getBestMove"
 */
void unDrop(char board[BOARD_ROWS][BOARD_COLS],int col){
    for (int i = 0; i < BOARD_ROWS; i++) {
        if (board[i][col] != ' ') { 
            board[i][col] = ' ';    
            return;                 
        }
    }
}

/**
 * Function: getBestMove
 * ---------------------
 * Determines the optimal move for the Computer.
 * Uses a priority-based system:
 * 1. Win
 * 2. Block
 * 3. Strategy: Build a sequence (Random).
 */
int getBestMove(char board[BOARD_ROWS][BOARD_COLS]){
    printf("h");
    //Priority 1 - Win
    for(int i=0;i<BOARD_COLS;i++){
        if(dropPiece(board,i,'O')){
            if(validateWin(board)==1){
                unDrop(board,i);
                return i;

            }
            unDrop(board,i);
        }
    }

    //Priority 2 - Block
    for(int i=0;i<BOARD_COLS;i++){
        if(dropPiece(board,i,'X')){
            if(validateWin(board)==1){
                unDrop(board,i);
                return i;

            }
            unDrop(board,i);
        }
    }

    //Priority 3 - Build something randomly
    return getComputerMove(board);

}








