#include <iostream>

const int boardSize = 8;


void initBoard(int board[boardSize][boardSize], int boardSize)
{
    for (int i = 0; i < boardSize - 1; i ++)
        board[0][i] = 1;
    
    for (int i = 0; i < boardSize - 1; i ++)
        board[i][0] = 1;

    for (int i = 1; i < boardSize - 1; i ++)
    {
        for (int j = 1; j < boardSize - 1; j ++)
        {
            board[i][j] = board[i - 1][j] + board[i][j - 1];
            // board[i][j] = 0;
        }
    }
}

void printBoard(int board[boardSize][boardSize], int boardSize)
{
    for (int i = 0; i < boardSize - 1; i ++)
    {
        for (int j = 0; j < boardSize - 1; j ++)
            std::cout << board[i][j] << " ";

        std::cout << std::endl;
    }
}

int main(int argc, char** argv)
{

    int board[boardSize][boardSize];
    initBoard(board, boardSize);
    printBoard(board, boardSize);



    exit(0);
}

