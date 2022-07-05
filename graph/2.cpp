// Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector <pair<int, int>>d = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
        {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    int n, m;
  public:
    // Function to find the number of islands.
    void helper(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j)
    {
        if( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        
        helper(grid, visited, i+d[0].first, j+d[0].second);
        helper(grid, visited, i+d[1].first, j+d[1].second);
        helper(grid, visited, i+d[2].first, j+d[2].second);
        helper(grid, visited, i+d[3].first, j+d[3].second);
        helper(grid, visited, i+d[4].first, j+d[4].second);
        helper(grid, visited, i+d[5].first, j+d[5].second);
        helper(grid, visited, i+d[6].first, j+d[6].second);
        helper(grid, visited, i+d[7].first, j+d[7].second);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visited[i][j] || grid[i][j] == '0') continue;
                
                count++;
                helper(grid, visited, i, j);
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends