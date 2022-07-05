// Link: https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    int n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    public:
    //Function to find whether a path exists from the source to destination.
    bool helper(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0) return false;
        if(visited[i][j]) return false;
        visited[i][j] = true;
        if(grid[i][j] == 2) return true;
        
        if(helper(i+dx[0], j+dy[0], grid, visited) || helper(i+dx[1], j+dy[1], grid, visited)
        || helper(i+dx[2], j+dy[2], grid, visited) || helper(i+dx[3], j+dy[3], grid, visited))
            return true;
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        n = grid.size();
        int si = -1, sj = -1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                    break;
                }
            }
            if(si != -1) break;
        }
        return helper(si, sj, grid, visited);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends