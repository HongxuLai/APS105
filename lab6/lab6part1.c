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

        if (player == P1) player = P2;
        else player = P1;
    }
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
    printf("\n");
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
        printf("Player %c enter column: ", p);
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
