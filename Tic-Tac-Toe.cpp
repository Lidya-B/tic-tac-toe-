//*******************************************************************************************************
//
//		File:					Tic-Tac-Toe.cpp
//
//		This a simple tic tac toe game
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
//*******************************************************************************************************

using namespace std;

//*******************************************************************************************************


void displayInitialBoard();
void displayBoard(const char board[9]);
bool compareSquares(char b1, char b2, char b3);
char winnerCheck(const char board[9]);
void askPlayerX(char board[]);
void emptySquares(const char board[9], int squares[9], int& num);
int playerCanWin(const char board[9], char player);

//*******************************************************************************************************

int main()
{
    srand(time(NULL));
    char board[9] =
    { ' ',' ',' ',
    ' ',' ',' ',
    ' ',' ',' ' };
    displayInitialBoard();
    int squares[9];
    int noUsedSquares = 9;
    int n;
    char playerTurn = 'X';
    char winner = ' ';
    while ((noUsedSquares > 0) && (winner == ' '))
    {
        emptySquares(board, squares, noUsedSquares);
        if (playerTurn == 'X')
        {
            askPlayerX(board);
            displayBoard(board);
            playerTurn = 'O';
        }
        else
        {
            int winningMove = playerCanWin(board, 'O');
            if (winningMove != -1) {
                board[winningMove] = 'O'; 
            }
            else {
                n = rand() % noUsedSquares;
                board[squares[n]] = playerTurn; 
            }

            displayBoard(board);
            playerTurn = 'X'; 
        }
        --noUsedSquares;
        winner = winnerCheck(board);
    }
    if (winner == 'X')
    {
        cout << "X won the game" << endl;
    }
    else if (winner == 'O')
    {
        cout << "O won the game" << endl;
    }
    else
    {
        cout << "The game was tied" << endl;
    }
    return 0;
}

//*******************************************************************************************************

void displayInitialBoard()
{
    cout << endl << endl;
    int row = 0;
    cout << "These are the numbers for each square:" << endl << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << " " << row + 1 << " | " << row + 2 << " | " << row + 3 << endl;
        if ((row == 0) || (row == 3)) 
        {
            cout << " -----------" << endl;
        }
        row += 3;
    }
    cout << endl << endl;
}

//*******************************************************************************************************

void displayBoard(const char board[9])
{
    cout << endl;
    int row = 0;
    for (int i = 0; i < 3; ++i)
    {
        cout << " " << board[row] << " | " << board[row + 1] << " | " << board[row + 2] << endl;
        if ((row == 0) || (row == 3))
        {
            cout << " -----------" << endl;
        }
        row += 3;
    }
    cout << endl;
}

//*******************************************************************************************************

bool compareSquares(char b1, char b2, char b3)
{
    return (b1 == b2) && (b2 == b3) && (b1 != ' ');
}

//*******************************************************************************************************

char winnerCheck(const char board[9])
{
    
    for (int i = 0; i < 9; i += 3)
    {
        if (compareSquares(board[i], board[i + 1], board[i + 2]))
        {
            return board[i];
        }
    }

    
    for (int i = 0; i < 3; ++i)
    {
        if (compareSquares(board[i], board[i + 3], board[i + 6]))
        {
            return board[i];
        }
    }

    
    if (compareSquares(board[0], board[4], board[8]))
    {
        return board[0];
    }
    if (compareSquares(board[2], board[4], board[6]))
    {
        return board[2];
    }

    return ' '; 
}

//*******************************************************************************************************

void askPlayerX(char board[])
{
    bool validChoice;
    int n;
    do
    {
        cout << "Enter a square number: ";
        cin >> n;
        --n;
        if (board[n] == ' ')
        {
            validChoice = true;
            board[n] = 'X';
        }
        else
        {
            cout << endl << " Must choose an empty square" << endl << endl;
            validChoice = false;
        }
    } while (validChoice == false);
}

//*******************************************************************************************************

void emptySquares(const char board[9], int squares[9], int& num)
{
    int row = 0;
    int col = 0;
    num = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] == ' ')
        {
            squares[num] = i;
            ++num;
        }
    }
}

//*******************************************************************************************************

int playerCanWin(const char board[9], char player)
{

    char opponent = (player == 'X') ? 'O' : 'X';

    for (int i = 0; i < 3; ++i)
    {
        if ((board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == ' ') ||
            (board[i * 3] == player && board[i * 3 + 1] == ' ' && board[i * 3 + 2] == player) ||
            (board[i * 3] == ' ' && board[i * 3 + 1] == player && board[i * 3 + 2] == player)) 
        {
            if (board[i * 3] == ' ')
            {
                return i * 3;
            }
            else if (board[i * 3 + 1] == ' ') 
            {
                return i * 3 + 1;
            }
            else {
                return i * 3 + 2;
            }
        }
        if ((board[i] == player && board[i + 3] == player && board[i + 6] == ' ') ||
            (board[i] == player && board[i + 3] == ' ' && board[i + 6] == player) ||
            (board[i] == ' ' && board[i + 3] == player && board[i + 6] == player))
        {
            if (board[i] == ' ')
            {
                return i;
            }
            else if (board[i + 3] == ' ')
            {
                return i + 3;
            }
            else 
            {
                return i + 6;
            }
        }
        if ((board[i * 3] == opponent && board[i * 3 + 1] == opponent && board[i * 3 + 2] == ' ') ||
            (board[i * 3] == opponent && board[i * 3 + 1] == ' ' && board[i * 3 + 2] == opponent) ||
            (board[i * 3] == ' ' && board[i * 3 + 1] == opponent && board[i * 3 + 2] == opponent)) 
        {
            if (board[i * 3] == ' ') 
            {
                return i * 3;
            }
            else if (board[i * 3 + 1] == ' ') 
            {
                return i * 3 + 1;
            }
            else
            {
                return i * 3 + 2;
            }
        }
        if ((board[i] == opponent && board[i + 3] == opponent && board[i + 6] == ' ') ||
            (board[i] == opponent && board[i + 3] == ' ' && board[i + 6] == opponent) ||
            (board[i] == ' ' && board[i + 3] == opponent && board[i + 6] == opponent))
        {
            if (board[i] == ' ')
            {
                return i;
            }
            else if (board[i + 3] == ' ') 
            {
                return i + 3;
            }
            else
            {
                return i + 6;
            }
        }
    }

    if ((board[0] == player && board[4] == player && board[8] == ' ') ||
        (board[0] == player && board[4] == ' ' && board[8] == player) ||
        (board[0] == ' ' && board[4] == player && board[8] == player))
    {
        if (board[0] == ' ') 
        {
            return 0;
        }
        else if (board[4] == ' ')
        {
            return 4;
        }
        else 
        {
            return 8;
        }
    }

    if ((board[2] == player && board[4] == player && board[6] == ' ') ||
        (board[2] == player && board[4] == ' ' && board[6] == player) ||
        (board[2] == ' ' && board[4] == player && board[6] == player)) 
    {
        if (board[2] == ' ')
        {
            return 2;
        }
        else if (board[4] == ' ')
        {
            return 4;
        }
        else 
        {
            return 6;
        }
    }

    if ((board[0] == opponent && board[4] == opponent && board[8] == ' ') ||
        (board[0] == opponent && board[4] == ' ' && board[8] == opponent) ||
        (board[0] == ' ' && board[4] == opponent && board[8] == opponent))
    {
        if (board[0] == ' ') 
        {
            return 0;
        }
        else if (board[4] == ' ')
        {
            return 4;
        }
        else
        {
            return 8;
        }
    }

    if ((board[2] == opponent && board[4] == opponent && board[6] == ' ') ||
        (board[2] == opponent && board[4] == ' ' && board[6] == opponent) ||
        (board[2] == ' ' && board[4] == opponent && board[6] == opponent)) 
    {
        if (board[2] == ' ')
        {
            return 2;
        }
        else if (board[4] == ' ') 
        {
            return 4;
        }
        else 
        {
            return 6;
        }
    }

    return -1; 
}

//*******************************************************************************************************

