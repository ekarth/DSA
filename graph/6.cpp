// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/

// Approach: union-find algorithm to check cycle in undirected graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int find_parent(vector<int> &parent, int v)
    {
        if(parent[v] == v) return v;
        return find_parent(parent, parent[v]);
    }

    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> parent(V);
        for(int i = 0; i < V; i++) parent[i] = i;
        
        for(int i = 0; i < V; i++)
        {
            for(int j: adj[i])
            {
                if(j < i) continue;
                
                int par_i = find_parent(parent, i);
                int par_j = find_parent(parent, j);
                
                if(par_i == par_j) return true;
                
                parent[par_i] = par_j;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends