// Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/

// Approach: DFS

// Solution: Everytime find a 1 that has not been visited added it to the answer and 
//           move in all 8 possible directions.
//           Final answer is the maximum of all the received answers.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int n, m;
    public:
    //Function to find unit area of the largest region of 1s.
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return 0;

        if(visited[i][j]) return 0;

        visited[i][j] = true;
        int ans = 1+
        helper(grid, i+dx[0], j+dy[0], visited)+
        helper(grid, i+dx[1], j+dy[1], visited)+
        helper(grid, i+dx[2], j+dy[2], visited)+
        helper(grid, i+dx[3], j+dy[3], visited)+
        helper(grid, i+dx[4], j+dy[4], visited)+
        helper(grid, i+dx[5], j+dy[5], visited)+
        helper(grid, i+dx[6], j+dy[6], visited)+
        helper(grid, i+dx[7], j+dy[7], visited);
        return ans;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visited[i][j]) continue;
                ans = max(ans, helper(grid, i, j, visited));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends