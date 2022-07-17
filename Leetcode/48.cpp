// Link: https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void rotate(vector<vector<int>>& m) 
    {
        int n = m.size();
        int row = 0;
        int col = n;

        // Transpose of a matrix
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                swap(m[i][j], m[j][i]);
            }
        }

        // Mirror of transposed matrix
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                swap(m[i][j], m[i][n-j-1]);
            }
        }
    }
};

int main()
{
    // vector<vector<int>> m = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    obj.rotate(m);

    for(auto row: m)
    {
        for(int val: row) cout << val << " ";
        cout << endl;
    }
    return 0;
}