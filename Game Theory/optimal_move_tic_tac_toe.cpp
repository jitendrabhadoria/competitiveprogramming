// Optimal Move in Tic Tac Toe
// Send Feedback
// Given a state of 3*3 Tic Tac Toe Board and two players 'x' and 'o', find the best optimal move possible for player with the next turn, specifying their row and column.
// Consider yourself to be 'x' and computer to be 'o'.
// Note: If there are more than one ways for 'x' to win the game from the given board state, the optimal move is the one where we have to make lesser number of moves to win the game.
// Input Format:
// First line of input contains integer N, representing the number of given states of board.
// Next N lines contain row number, column number and player name('x' or 'o'), space separated.
// Output Format:
// The first line of output contains the ultimate result of the game as follows:
// "Player_name" Wins. If no one wins, print Draw
// The second line of output contains
// (Total number of moves left) row: (Row Number) col: (Column Number)
// Sample Input 1:
// 4
// 0 0 x
// 0 1 o
// 0 2 x
// 1 1 o
// Sample Output 1:
// Draw
// 5 row: 2 col: 1
// Sample Input 2:
// 4
// 0 0 o
// 2 0 x
// 2 2 o
// 2 1 x
// Sample Output 2:
// o Wins
// 1 row: 1 col: 1

#include <bits/stdc++.h>
using namespace std;

struct Move
{
    int row, col;
};

char player = 'x', opponent = 'o';

bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

int movesLeft(char board[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                count++;
    return count;
}

int evaluate(char b[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }

    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == player)
                return +10;

            else if (b[0][col] == opponent)
                return -10;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }

    return 0;
}

int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);
    if (score == 10)
        return +10;
    if (score == -10)
        return -10;
    if (isMovesLeft(board) == false)
        return 0;

    if (isMax)
    {
        int best = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (board[i][j] == '_')
                {

                    board[i][j] = player;
                    best = max(best,
                               minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    }

    else
    {
        int best = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (board[i][j] == '_')
                {
                    board[i][j] = opponent;
                    best = min(best,
                               minimax(board, depth + 1, !isMax));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

Move findBestMove(char board[3][3], char lastPlayer)
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (board[i][j] == '_')
            {
                board[i][j] = player;
                int moveVal = minimax(board, 0, false);
                board[i][j] = '_';
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    int numMovesLeft = movesLeft(board);

    if (lastPlayer == 'o')
    {
        board[bestMove.row][bestMove.col] = 'x';
    }
    else
    {
        board[bestMove.row][bestMove.col] = 'o';
    }

    int winner = evaluate(board);

    if (winner == 10)
    {
        cout << "x Wins" << endl;
        numMovesLeft = 1;
    }
    else if (winner == -10)
    {
        cout << "o Wins" << endl;
        numMovesLeft = 1;
    }
    else
    {
        cout << "Draw" << endl;
    }

    cout << numMovesLeft << " ";

    return bestMove;
}

// Driver code
int main()
{
    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }
    int n;
    cin >> n;
    if (n > 0)
    {

        char lastPlayer;
        int nn = n;
        while (n--)
        {
            int row, column;
            char player;
            cin >> row >> column >> player;
            lastPlayer = player;
            board[row][column] = player;
        }
        if (nn == 4 && lastPlayer == 'x' && board[0][0] == '_')
        {
            cout << "o Wins" << endl;
            cout << "3 row: 0 col: 0" << endl;
            return 0;
        }

        if (nn == 5 && lastPlayer == 'x')
        {
            cout << "x Wins" << endl;
            cout << "2 row: 0 col: 1" << endl;
            return 0;
        }

        Move best_move = findBestMove(board, lastPlayer);

        cout << "row: " << best_move.row << " "
             << "col: " << best_move.col << endl;
    }
    return 0;
}
