// Link: https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1/

// Approach: BFS as we have to find level and BFS move level to level 
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the level of node X.
	
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                if(node == X) return level;
                for(auto i: adj[node])
                {
                    if(visited[i]) continue;
                    q.push(i);
                    visited[i] = true;
                }
            }
            level++;    
        }
        return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends