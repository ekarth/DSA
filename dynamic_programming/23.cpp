// Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        // x: lenght of string s1 
        // y: length of string s2 

        //create matrix of (x+1, y+1)
        s1 = "1" + s1;
        s2 = "2" + s2;

        vector<vector<int>> c(x+1, vector<int>(y+1));

        for(int i = 0; i <= x; i++) c[i][0] = 0; // all entries of first column to 0

        for(int j = 0; j <= y; j++) c[0][j] = 0; // all entries offirst row to 0

        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                if(s1[i] == s2[j])
                {
                    c[i][j] = c[i-1][j-1] + 1;
                }
                else if(c[i-1][j]  >= c[i][j-1] )
                {
                    c[i][j] = c[i-1][j];
                }
                else if(c[i-1][j]  < c[i][j-1] )
                {
                    c[i][j] = c[i][j-1];
                }
            }
        }

        return c[x][y];
    }
};

int main()
{
    int t, n, k, x, y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;          // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }

    return 0;
}

// } Driver Code Ends