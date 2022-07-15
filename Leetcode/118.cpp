// Link: https://leetcode.com/problems/pascals-triangle/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> triangle(n); // ans to return

        triangle[0].push_back(1);
        if(n == 1) return triangle; // if number of rows == 1 return

        for(int i = 1; i < n; i++)
        {
            triangle[i].push_back(1); // first value of each row of pascal's triangle is 1
            for(int j = 0; j < triangle[i-1].size() - 1; j++)
            {
                triangle[i].push_back(triangle[i-1][j]+triangle[i-1][j+1]);
            }
            triangle[i].push_back(1); // last value of each row of pascal's triangle is 1
        }
        return triangle;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    vector<vector<int>> ans = obj.generate(n);

    for(auto row: ans)
    {
        for(auto val: row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}