#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"
#include "function.c"
#define MAX_ROW 6
#define MAX_COL 7
#define NUM_OF_PLACES 42
#define player_x  'X'
#define player_o  'O'
                                            
static int u;                                            
int main(){

printf("Welcome!\n");
printMatrix(matrix);
int i,j,counter,win;
int undo[NUM_OF_PLACES];
bool player_turn = false;
bool flag = true;
u = 0;

while(flag){
    if(!player_turn){
        insertion(matrix, player_x, undo);
        player_turn = true;
    }
    else{
    insertion(matrix, player_o, undo);
    player_turn=false;
    }
    
    printMatrix(matrix);
    win = check_winner(matrix);
        if(win>0){
            if (win==1)
                printf("Player X wins!");
            else if(win==2)
                printf("Player O wins!");
            else 
            if(win==3)
                printf("It's a tie!");
            flag=false;
            
        }
    }
    return 0;
}