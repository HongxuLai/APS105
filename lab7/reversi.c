#include <stdio.h>
#include <stdbool.h>

void initializeBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool isValidMove(char board[][26], int n, int row, int col, char colour);
void printValidMove(char board[][26], int n, char colour);
void makeMove(char board[][26], int n, int row, int col, char colour);


int main()
{
    // get n at first 
    int n = 0; 
    printf("Enter the board dimension: ");
    scanf("%d", &n);

    // initialize and print the board 
    char board[26][26];
    initializeBoard(board, n);
    printBoard(board, n);

    // get the input of some index
    char config[4];
    printf("Enter board configuration:\n");
    while(1)
    {
        scanf("%s", config);
        if(config[0] == '!' && config[1] == '!' && config[2] == '!') break;

        int row = config[1] - 'a';
        int col = config[2] - 'a';
        board[row][col] = config[0];
    }
    printBoard(board, n);

    // print all valid move for both white and black
    printValidMove(board, n, 'W');
    printValidMove(board, n, 'B');

    printf("Enter a move:\n");
    char move[4];
    scanf("%s", move);
    int mr = move[1] - 'a';
    int mc = move[2] - 'a';
    // check if this move is valid 
    if(isValidMove(board, n, mr, mc, move[0]))
    {
        printf("Valid move.\n");
        makeMove(board, n, mr, mc, move[0]);
    }
    else
    {
        printf("Invalid move.\n");
    }

    printBoard(board, n);
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

// print all valid move place for this color tile
void printValidMove(char board[][26], int n, char colour)
{
    printf("Available moves for %c:\n", colour);
    for(int r = 0; r < n; r ++)
    {
        for(int c = 0; c < n; c ++)
        {
            if(board[r][c] == 'U')
            {
                if(isValidMove(board, n, r, c, colour))
                {
                    printf("%c%c\n", 'a' + r, 'a' + c);
                }
            }
        }
    }
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