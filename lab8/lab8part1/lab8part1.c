#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "lab8part1.h"

void initializeBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool isValidMove(char board[][26], int n, int row, int col, char colour);
void makeMove(char board[][26], int n, int row, int col, char colour);
int countFlipsInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
int getMoveScore(char board[][26], int n, int row, int col, char colour);
void getBestMove(char board[][26], int n, char colour, int *bestRow, int *bestCol);
char winner(char board[][26], int n);
void computerMove(char board[][26], int n, char complayer);
bool playerMove(char board[][26], int n, char player);
bool hasValidMove(char board[][26], int n, char colour);

int main()
{
    // get n at first 
    int n = 0; 
    printf("Enter the board dimension: ");
    scanf("%d", &n);

    // get the computer's chess
    char player;
    char complayer;
    printf("Computer plays (B/W): ");
    scanf(" %c", &complayer);
    if(complayer == 'B') player = 'W';
    else player = 'B';

    // initialize and print the board 
    char board[26][26];
    initializeBoard(board, n);
    printBoard(board, n);

    char current = 'B';
    while(1)
    {
        bool blackHasMove = hasValidMove(board, n, 'B');
        bool whiteHasMove = hasValidMove(board, n, 'W');

        if (!blackHasMove && !whiteHasMove)
        {
            break;
        }

        if (hasValidMove(board, n, current))
        {
            if (current == player)
            {
                if (!playerMove(board, n, player))
                {
                    printf("Invalid move.\n");
                    break;
                }
            }
            else
            {
                computerMove(board, n, complayer);
            }

            printBoard(board, n);
        }
        else
        {
            printf("%c player has no valid move.\n", current);
        }

        if (current == 'B') current = 'W';
        else current = 'B';
        
    }

    char win = winner(board, n);
    if (win == 'B') printf("B player wins.\n");
    else if (win == 'W') printf("W player wins.\n");
    else printf("Draw!\n");
        
    return 0;
}

// initialize the board
void initializeBoard(char board[][26], int n)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            board[r][c] = 'U'; // all set to 'U' at first
        }
    }

    // the mid four part set to 'W'/'B'
    board[n / 2 - 1][n / 2 - 1] = 'W';
    board[n / 2 - 1][n / 2] = 'B';
    board[n / 2][n / 2 - 1] = 'B';
    board[n / 2][n / 2] = 'W';
}

// print the board
void printBoard(char board[][26], int n)
{
    // first row: "  abcdef..."
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("%c", 'a' + i);
    }
    printf("\n");

    for (int r = 0; r < n; r++)
    {
        // each row has a letter in sequence
        printf("%c ", 'a' + r);
        for (int c = 0; c < n; c++)
        {
            printf("%c", board[r][c]);
        }
        printf("\n");
    }
}

// check if this index is within the board
bool positionInBounds(int n, int row, int col)
{
    if(0 <= row && row < n && 0 <= col && col < n) return true;
    else return false;
}

//check if this direction is legal to add new tile
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    int nr = row + deltaRow;
    int nc = col + deltaCol;
    // new index must be legal and cannot be the same as origin one or 'U'
    if(!positionInBounds(n, nr, nc) || board[nr][nc] == colour || board[nr][nc] == 'U')
    {
        return false;
    }
    nr += deltaRow;
    nc += deltaCol;
    while (positionInBounds(n, nr, nc) && board[nr][nc] != colour && board[nr][nc] != 'U')
    {
        nr += deltaRow;
        nc += deltaCol;
    }
    if(positionInBounds(n, nr, nc) && board[nr][nc] == colour) return true;
    else return false;
}

// from 8 directions to check if this move is valid
bool isValidMove(char board[][26], int n, int row, int col, char colour)
{
    // tile to be checked must be within the board and not be 'U'
    if (!positionInBounds(n, row, col) || board[row][col] != 'U')
    {
        return false;
    }
    
    for(int deltaRow = -1; deltaRow <= 1; deltaRow++)
    {
        for(int deltaCol = -1; deltaCol <= 1; deltaCol++)
        {
            if(deltaRow == 0 && deltaCol == 0) continue;
            if(checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)) return true;
        }
    }
    return false;
}

// change the tile at first, and check if any other tile needed to be changed from 8 directions
void makeMove(char board[][26], int n, int row, int col, char colour)
{
    board[row][col] = colour;
    for(int deltaRow = -1; deltaRow <= 1; deltaRow ++)
    {
        for(int deltaCol = -1; deltaCol <= 1; deltaCol ++)
        {
            if(deltaRow == 0 && deltaCol == 0) continue;
            if(checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol))
            {
                int nr = row + deltaRow;
                int nc = col + deltaCol;
                while (positionInBounds(n, nr, nc) && board[nr][nc] != colour && board[nr][nc] != 'U')
                {
                    board[nr][nc] = colour;
                    nr += deltaRow;
                    nc += deltaCol;
                }
            }
        }
    }
}

// calculate the score for one direction
int countFlipsInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    if(!checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)) return 0;

    int nr = row + deltaRow;
    int nc = col + deltaCol;
    int count = 0;

    while(positionInBounds(n, nr, nc) && board[nr][nc] != colour && board[nr][nc] != 'U')
    {
        nr += deltaRow;
        nc += deltaCol;
        count ++;
    }

    return count;
}

// get one possble move's total score
int getMoveScore(char board[][26], int n, int row, int col, char colour)
{
    if (!positionInBounds(n, row, col) || board[row][col] != 'U')
    {
        return 0;
    }

    int totalScore = 0;

    for (int deltaRow = -1; deltaRow <= 1; deltaRow++)
    {
        for (int deltaCol = -1; deltaCol <= 1; deltaCol++)
        {
            if (deltaRow == 0 && deltaCol == 0) continue;

            totalScore += countFlipsInDirection(board, n, row, col, colour, deltaRow, deltaCol);
        }
    }

    return totalScore;
}

// for every where, calculate the score and get the maxScore
void getBestMove(char board[][26], int n, char colour, int *bestRow, int *bestCol)
{
    int maxScore = 0;
    *bestRow = -1;
    *bestCol = -1;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            int score = getMoveScore(board, n, r, c, colour);
            if(score > maxScore)
            {
                *bestRow = r;
                *bestCol = c;
                maxScore = score;
            }
        }
    }
}

// judge who wins the game
char winner(char board[][26], int n)
{
    int countB = 0;
    int countW = 0;
    for(int r = 0; r < n;r ++)
    {
        for(int c = 0; c < n; c++)
        {
            if(board[r][c] == 'B') countB ++;
            else if(board[r][c] == 'W') countW ++;
        }
    }
    if(countB > countW) return 'B';
    else if(countB < countW) return 'W';
    else return 'D';
}

// computer move
void computerMove(char board[][26], int n, char complayer)
{
    int bestRow;
    int bestCol;
    getBestMove(board, n, complayer, &bestRow, &bestCol);
    if(bestRow != -1)
    {
        printf("Computer places %c at %c%c.\n", complayer, 'a' + bestRow, 'a' + bestCol);
        makeMove(board, n, bestRow, bestCol, complayer);
    }
    else 
    {
        return;
    }
}

// player move
bool playerMove(char board[][26], int n, char player)
{
    char inputPlayer[3];
    printf("Enter move for colour %c (RowCol): ", player);
    scanf("%2s", inputPlayer);
    int row = inputPlayer[0] - 'a';
    int col = inputPlayer[1] - 'a';
    if(isValidMove(board, n, row, col, player))
    {
        makeMove(board, n, row, col, player);
        return true;
    }
    else
    {
        return false;
    }
}

// check if this player has valid move now
bool hasValidMove(char board[][26], int n, char colour)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (isValidMove(board, n, r, c, colour))
            {
                return true;
            }
        }
    }
    return false;
}