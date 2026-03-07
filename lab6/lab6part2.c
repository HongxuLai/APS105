#include <stdio.h>
#include <stdbool.h>
#define WIDTH 7
#define HEIGHT 6
#define CONNECT 4
#define P1 'X'
#define P2 'O'
#define EMPTY '-'

void clearBoard(char board[HEIGHT][WIDTH]);
void printBoard(char board[HEIGHT][WIDTH]);
bool checkFull(char board[HEIGHT][WIDTH], int col);
int getPlayerColumnChoice(char board[HEIGHT][WIDTH], char p);
void makeMove(char board[HEIGHT][WIDTH], char p, int col);
bool checkPosition(char board[][WIDTH], int col, int row);
bool checkRow(char board[][WIDTH], int col, int row);
bool checkCol(char board[][WIDTH], int col, int row);
bool checkDiagonal(char board[][WIDTH], int col, int row);
bool checkForWin(char board[][WIDTH]);

int main()
{
    char board[HEIGHT][WIDTH];
    clearBoard(board);
    printBoard(board);
    char player = P1;
    int col;
    while (1)
    {
        col = getPlayerColumnChoice(board, player);
        if (col < 0) break;

        makeMove(board, player, col);
        printBoard(board);

        if (checkForWin(board))
        {
            printf("Player %c wins!\n", player);
            break;
        }

        if (player == P1)
        {
            player = P2;
        }
        else player = P1;
    }
    return 0;
}

// clear the board at first, use " - " to take place
void clearBoard(char board[HEIGHT][WIDTH])
{
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            board[r][c] = EMPTY;
        }
    }
}

// print the board column by column
void printBoard(char board[HEIGHT][WIDTH])
{
    for (int c = 0; c < WIDTH; c++)
    {
        printf("%d ", c);
    }
    printf("\n");

    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

// judge if the board is full
bool checkFull(char board[HEIGHT][WIDTH], int col)
{
    bool full = true;
    for (int r = 0; r < HEIGHT; r ++)
    {
        if (board[r][col] == EMPTY)
        {
            full = false;
            return full;
        }
    }
    return full;
}

// get the player's column choice
int getPlayerColumnChoice(char board[HEIGHT][WIDTH], char p)
{
    int col = 0;
    bool full = false;
    do
    {
        printf("Player %c enter column: \n", p);
        scanf("%d", &col);

        if (col < 0)
        {
            return -1;
        }
    } while (col >= WIDTH || checkFull(board, col));
    return col;
}

void makeMove(char board[HEIGHT][WIDTH], char p, int col)
{
    for (int r = HEIGHT - 1; r >= 0; r--)
    {
        if(board[r][col] == EMPTY)
        {
            board[r][col] = p;
            return;
        }
    }
}

bool checkPosition(char board[][WIDTH], int col, int row)
{
    if (board[row][col] == EMPTY) return false;
    if (checkRow(board, col, row)) return true;
    if (checkCol(board, col, row)) return true;
    if (checkDiagonal(board, col, row)) return true;
    return false;
}

// check the row
bool checkRow(char board[][WIDTH], int col, int row)
{
    int count = 1;
    int cl = col - 1;
    int cr = col + 1;
    for(; cl >= 0; cl --)
    {
        if(board[row][cl] == board[row][col])
        {
            count += 1;
            if(count == CONNECT) return true;
        }
        else break;
    }
    for(; cr < WIDTH; cr++)
    {
        if(board[row][cr] == board[row][col])
        {
            count += 1;
            if(count == CONNECT) return true;
        }
        else break;
    }
    return false;
}

// check the column
bool checkCol(char board[][WIDTH], int col, int row)
{
    int count = 1;
    int ro = row - 1;
    int ru = row + 1;
    for(; ro >= 0; ro--)
    {
        if (board[ro][col] == board[row][col])
        {
            count += 1;
            if(count == CONNECT) return true;
        }
        else break;
    }
    for(; ru < HEIGHT; ru++)
    {
        if (board[ru][col] == board[row][col])
        {
            count += 1;
            if (count == CONNECT) return true;
        }
        else break;
    }
    return false;
}

// check the diagonal
bool checkDiagonal(char board[][WIDTH], int col, int row)
{
    int cl;
    int cr;
    int ro;
    int ru;
    int count = 1;

    // check from left over from right under
    for(cl = col - 1, ro = row - 1; cl >= 0 && ro >= 0; cl --, ro --)
    {
        if(board[ro][cl] == board[row][col])
        {
            count += 1;
            if(count == CONNECT) return true;
        }
        else break;
    }
    for(cr = col + 1, ru = row + 1; cr < WIDTH && ru < HEIGHT; cr ++, ru ++)
    {
        if(board[ru][cr] == board[row][col])
        {
            count += 1;
            if(count == CONNECT) return true;
        }
        else break;
    }

    // check from left under from right over
    count = 1;
    for(cl = col - 1, ru = row + 1; cl >= 0 && ru < HEIGHT; cl --, ru ++)
    {
        if(board[ru][cl] == board[row][col])
        {
            count += 1;
            if(count == CONNECT) return true;
        }
        else break;
    }
    for(cr = col + 1, ro = row - 1; cr < WIDTH && ro >= 0; cr ++, ro --)
    {
        if(board[ro][cr] == board[row][col])
        {
            count += 1;
            if(count == CONNECT) return true;
        }
        else break;
    }

    return false;
}

bool checkForWin(char board[][WIDTH])
{
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (checkPosition(board, col, row))
            {
                return true;
            }
        }
    }
    return false;
}