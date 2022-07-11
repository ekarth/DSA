// Link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// in-space Solution
// no negative cycle detection and path reconstruction

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int k = 0; k < n; k++)
	    {
	        for(int i = 0; i < n; i++)
	        {
	            for(int j = 0; j < n; j++)
	            {
	               // if weight = -1 then there is no path to this vertex
	                if(matrix[i][k] == -1 || matrix[k][j] == -1) continue;
	                
	                // if path does not exist, then check using k
	                if(matrix[i][j] == -1) matrix[i][j] = matrix[i][k]+matrix[k][j];
	                else matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends