#include "logic.h"




void initBoard(char board[BOARD_ROWS][BOARD_COLS]){
    for(int i=0;i<BOARD_ROWS;i++){
        for(int j=0;j<BOARD_COLS;j++){
            board[i][j]=' ';
        }
    }
}

int dropPiece(char board[BOARD_ROWS][BOARD_COLS],int col,char piece){
    for(int i=BOARD_ROWS-1;i>=0;i--){
        if(board[i][col]==' '){
            board[i][col]=piece;
            return 1;
        }
    }
    return 0;
}

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
        for(int j=0;j<BOARD_COLS-3;j++){
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

int fullBoard(char board[BOARD_ROWS][BOARD_COLS]){
    for(int i=0;i<BOARD_ROWS;i++){
        for(int j=0;j<BOARD_COLS;j++){
            if(board[i][j]==' '){
                return 0;
            }
        }
    }
    return 1;
}










