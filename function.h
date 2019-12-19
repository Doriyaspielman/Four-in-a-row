#define NUM_OF_PLACES 42
#define MAX_ROW 6
#define MAX_COL 7

void printMatrix(char matrix[MAX_ROW][MAX_COL]);
int check_Input(char matrix[MAX_ROW][MAX_COL], char player);
int insertion(char matrix[MAX_ROW][MAX_COL], char player,int undo[NUM_OF_PLACES]);
int first_check(char matrix[MAX_ROW][MAX_COL]);
int second_check(char matrix[MAX_ROW][MAX_COL]);
int third_check(char matrix[MAX_ROW][MAX_COL]);
int fourth_check(char matrix[MAX_ROW][MAX_COL]);
int check_tie(char matrix[MAX_ROW][MAX_COL]);
int check_winner(char matrix[MAX_ROW][MAX_COL]);
//bool check_victory( int i,int j,char matrix[MAX_ROW][MAX_COL],char c);
