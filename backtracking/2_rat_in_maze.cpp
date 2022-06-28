// Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/

// Approach: Backtracking
// Space Complexity: O(Number of paths * Lenghts of paths)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<string> ans;
    public:
    void solver(vector<vector<int>> &m, int n, string s, int i, int j)
    {
        // cout << i << " " << j << " " << s << endl;
        if(i >= n || j >= n || i < 0 || j < 0) return; // grid constraints
        if(m[i][j] == 0) return; // unreachable

        if(i == n-1 && j == n-1)  // end of matrix
        {
            ans.push_back(s);
            return;
        }
        
        m[i][j] = 0;
        solver(m, n, s + "U", i-1, j); //UP
        solver(m, n, s + "D", i+1, j); //DOWN
        solver(m, n, s + "L", i, j-1); //LEFT
        solver(m, n, s + "R", i, j+1); //RIGHT
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        solver(m, n, "", 0, 0);
        return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > m(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin >> m[i][j];
        
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if(result.size() == 0) cout << -1;
        else
            for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;

    }
    return 0;
}