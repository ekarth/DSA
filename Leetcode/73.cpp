// Link: https://leetcode.com/problems/set-matrix-zeroes/

#include<bits/stdc++.h>
using namespace std;

// Using first row and first column as reference to store whether we have 0 in that particular row and column

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        
        int rows = m.size(), cols = m[0].size(), col = 1;
        
        for(int i = 0; i < rows; i++) 
        {
            if(m[i][0] == 0) 
            {
                col = 0;
            }
            
            for(int j = 1; j < cols; j++)
            {
                // check for every entry if its 0 update value in first col and first row to 0
                if(m[i][j] == 0) 
                {
                    m[i][0] = 0; // updation in first column to maintain row
                    m[0][j] = 0; // updation in first row to maintain column
                }
            }
        }
        
        // traversing the matrix in reverse order
        for(int i = rows-1; i >= 0; i--)
        {
            for(int j = cols-1; j >= 1; j--)
            {
                // if 0 is present in either row or column then update current value to 0
                if(m[i][0] == 0 || m[0][j] == 0) m[i][j] = 0; 
            }

            if(col == 0) m[i][0] = 0; // column == 0 then update value in first column also to 0.
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution obj;
    obj.setZeroes(matrix);

    for(auto row: matrix)
    {
        for(auto val: row) cout << val << " ";
        cout << endl;
    }

    return 0;
}