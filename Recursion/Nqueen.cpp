#include <bits\stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, vector<string> &board)
{
    // columns
    int dubcols = col;
    int dubrows = row;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    // rows
    col = dubcols;
    while (row >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
    }
    // upper left diagonal
    row = dubrows;
    col = dubcols;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = dubrows;
    col = dubcols;
    while (row >= 0 && col < n)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col++;
    }
    return true;
}

void generate(int rows, int n, vector<string> &board, vector<vector<string>> &ans)
{
    if (rows == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isValid(rows, col, n, board))
        {
            board[rows][col] = 'Q';
            generate(rows + 1, n, board, ans);
            board[rows][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n);
    string str(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = str;
    }
    vector<vector<string>> ans;
    generate(0, n, board, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    solveNQueens(n);
    return 0;
}