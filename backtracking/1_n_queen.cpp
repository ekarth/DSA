#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> board; // index will be taken as the row and value at index is column in which queen is placed
bool commonColumn(int col)
{
    // check if any queen is previously placed in the same column
    for(int i = 1; i <= n; i++)
    {
        if(board[i] == col) return true;
    }
    return false;
}
bool commonDiagonal(int row, int col)
{
    // check if the position is targrted by previously placed queens diagonally
    // check for both diagonals:
        // left-right and right-left (as absolute difference is taken)

    for(int i = 1; i < row; i++)
    {
        if(abs(i - row) == abs(board[i] - col)) return true;
    }
    return false;
}
void printBoard()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(board[i] == j) cout << "| * ";
            else cout << "|   ";
        }
        cout << "|" << endl;
    }
}
void print()
{
    for(int i = 1; i <= n; i++) 
    {
        cout << i << " " << board[i] << endl;
    }
    cout << endl;
}
void n_queen(int row)
{
    // cout << row << endl;
    if(row > n)
    {
        for(int i = 1; i <= n; i++) cout << board[i] << " ";
        cout << endl;
        printBoard();
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        
        if(commonColumn(i)) continue;
        if(commonDiagonal(row, i)) continue;
        board[row] = i;
        // print();
        n_queen(row+1);
        board[row] = 0;
        // print();
        // columns[row] = 0;
    }
}
int main()
{
    cin >> n;
    board.resize(n+1);
    n_queen(1);
    return 0; 
}