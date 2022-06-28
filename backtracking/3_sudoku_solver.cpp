// Link: https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1/

#include<bits/stdc++.h>
using namespace std;

#define N 9

class Solution 
{
    public:

    bool presentSameColumn(int grid[N][N], int col, int num)
    {
        for(int i = 0; i < N; i++)
        {
            if(grid[i][col] == num) return true;
        }
        return false;
    }

    bool presentSameRow(int grid[N][N], int row, int num)
    {
        for(int i = 0; i < N; i++) if(grid[row][i] == num) return true;
        return false;
    }

    bool presentSameBox(int grid[N][N], int row, int col, int num)
    {
        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;
        for(int i = start_row; i < start_row+3; i++)
        {
            for(int j = start_col; j < start_col+3; j++)
            {
                if(grid[i][j] == num) return true;
            }
        }
        return false;
    }

    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(grid[i][j] == 0)
                {
                    for(int num = 1; num <= 9; num++)
                    {
                        if(presentSameRow(grid, i, num) || presentSameColumn(grid, j, num) || presentSameBox(grid, i, j, num)) continue;
                        grid[i][j] = num;
                        // cout << i << " " << j << " " << num << endl;
                        if(SolveSudoku(grid)) return true;
                        grid[i][j] = 0;
                    }
                    if(grid[i][j] == 0) return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++) cout << grid[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int grid[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) cin >> grid[i][j];
        
        Solution ob;
        cout << endl;
        if(ob.SolveSudoku(grid)) ob.printGrid(grid);
        else cout << "No solution exists";

        cout << endl;
    }
    return 0;
}