#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"
#define MAX_ROW 6
#define MAX_COL 7
#define NUM_OF_PLACES 42
#define player_x  'X'
#define player_o  'O'


static int u;
char matrix[MAX_ROW][MAX_COL]= { {' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' '}};


void printMatrix(char matrix[MAX_ROW][MAX_COL]){
    printf("\n");
    int i,j,K;
    for(i=0;i<MAX_ROW;i++){
    for(j=0;j<MAX_COL;j++)
     printf("| %c ",matrix[i][j]);
     if(j==MAX_COL){
         printf("|"); 
     }
     printf("\n");   
    
    }
    for(K=1;K<=MAX_COL;K++)
    printf("  %d ",K);
    printf("\n");
    
}


int check_Input(char matrix[MAX_ROW][MAX_COL], char player){
    int input;
    printf("\n Player %c, please enter a column number (or 0 to undo):",player);
    if(scanf("%d" , &input) != 1){
        printf("Invalid input, bye-bye!");
        exit(0);
    }
    else{
        if(input>=0 && input<=MAX_COL){
           return input;  
        }
        else{
             printMatrix(matrix);
        printf("Invalid input, the number must be between 1 to 7:");
        return check_Input(matrix,player);
        }
    }
}
int insertion(char matrix[MAX_ROW][MAX_COL], char player,int undo[NUM_OF_PLACES]){
    int valid_input,current;
    valid_input=check_Input(matrix,player);
    int i,j,k,counter=0;
       if(valid_input==0){
       if(u == 0){
        printf("Board is empty - can't undo!");
        printf("Try again:");
        return insertion(matrix,player,undo); 
        }
    
        else{ //undo
         current=undo[u-1];
         printf("current is: %d",current);
          for(i = 0; i < MAX_ROW; i++){
              if(matrix[i][current-1] != ' '){
                  matrix[i][current-1] = ' ';
                  u--;
                  break;
              }
          }
        } 
        }
  
    else{
      for (i=MAX_ROW-1; i>=-1; i--){
        if(i==-1){
            printf("Invalid input, this column is full. Please choose another one:");
            return insertion(matrix,player,undo); 
            }
        if(matrix[i][valid_input-1]==' '){
            matrix[i][valid_input-1]=player;
            undo[u]=valid_input;//insert to undo array
            u++;
           break;
        }
      }
    }

    return 1;
}
//all the funtions to check if there is a winner:
int first_check(char matrix[MAX_ROW][MAX_COL]){
   int count;
    int i,j;
    int check_4=0;
    for( i=0 ; i<MAX_ROW ; i++){
         for ( j=0 ; j<MAX_COL-3 ; j++){
            while(check_4<4){
                if(matrix[i][j+check_4] == matrix[i][j]){
                    count++;
                }
                else{
                    count=0;
                    break;}
                    check_4++;
            }
            check_4=0;
            if (count == 4){
                if (matrix[i][j] == player_x){
                    return 1;
                }
                else if (matrix[i][j] == player_o){
                    return 2;
                }
            }
            count = 0;
         }  
    } 
 return 0;
}

int second_check(char matrix[MAX_ROW][MAX_COL]){
  int count= 0;
  int i,j;
  int check_4=0;
    for( i=0 ; i< MAX_ROW-3 ; i++){
         for ( j=0 ; j<MAX_COL ; j++){
            while(check_4<4){
                if(matrix[i+check_4][j] == matrix[i][j]){
                    count++;
                   
                }
                else{
                    count=0; break;}
                    check_4++;
                }
                check_4=0;
            if (count == 4){
                if (matrix[i][j] == player_x){
                    return 1;
                }
                else if (matrix[i][j] == player_o){
                    return 2;
                }
            }
            count = 0;
            }
         }
     return 0;
}

int third_check(char matrix[MAX_ROW][MAX_COL]){
    int count= 0; 
    int i,j;
    int check_4=0;
    for( i=0 ; i< MAX_ROW-3 ; i++){
         for ( j=0 ; j<MAX_COL ; j++){
             while(check_4<4){
                if(matrix[i+check_4][j] == matrix[i][j]){
                    count++; 
                }
                else{
                    count=0; break;}
                    check_4++;
                }
                check_4=0;
            if (count == 4){
                if (matrix[i][j] == player_x){
                    return 1;
                }
                else if (matrix[i][j] == player_o){
                    return 2;
                }
            }
            count = 0;
            }
         }
         return 0;
}

int fourth_check(char matrix[MAX_ROW][MAX_COL]){
  int count = 0;
  int i,j;
  int check_4=0;
    for(i=0 ; i<MAX_ROW-3 ; i++){
         for ( j=3 ; j<MAX_COL ; j++){
            while(check_4<4){
                if(matrix[i+check_4][j-check_4] == matrix[i][j]){
                    count++;
                }
                else{
                    count=0;
                }
                check_4++;
            }
            check_4=0;
            if (count == 4){
                if (matrix[i][j] == player_x){
                    return 1;
                }
                else if (matrix[i][j] == player_o){
                    return 2;
                }
            }
        }
    }
    return 0;
}


int check_tie(char matrix[MAX_ROW][MAX_COL]){
    if (u == NUM_OF_PLACES){
        return 3;
    }
    return 0;   
}

int check_winner(char matrix[MAX_ROW][MAX_COL]) {
int i =first_check(matrix);
int i2=second_check(matrix);
int i3=third_check(matrix);
int i4=fourth_check(matrix);
int i5 = check_tie(matrix);
    if(i!=0) return i;
    else if(i2!=0)return i2;
    else if(i3!=0)return i3;
    else if(i4!=0)return i4;
    else if(i5!=0)return i5;
return 0;
}
