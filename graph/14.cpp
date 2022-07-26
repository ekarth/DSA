// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

// Approach:
//     Using DFS to solve the problem.
//     As we go in depth, if we can reach any node of the path then cycle exist.
//     Using visited array to check if the node is visited or not and initialising it with the unique number which determines the current 
//     path of the DFS.
//     Also maintaining 's' vector for checking if the node still exist in the path or not (mainly used after recursion).
//     Note: Using vector not stack for s for the sole purpose of searching O(1) time. 
//     if the node is in the current path (s[node] is true and visited[node] == current path number) than path exist.
class Solution {
  public:
    bool DFS(int v, vector<int> &visited, vector<int> adj[], int no, vector<bool> &s)
    {
        
        if(visited[v] == no && s[v]) return true; // if path exist
        if(visited[v] != -1) return false; // if node already visited

        // Adding current node to path 
        visited[v] = no;
        s[v] = true;
        
        // For every neighbor applying DFS 
        for(auto neighbor: adj[v])
        {
            if(DFS(neighbor, visited, adj, no, s)) return true;
            s[neighbor] = false; // removing neighbor from path as no path is found and we go to new neighbor
        }
        return false;
    }

    bool isCyclic(int n, vector<int> adj[]) 
    {
        vector<int> visited(n, -1); // initialisng visited array
        vector<bool> s(n, false); // initialising stack (s) array
        
        for(int i = 0; i < n; i++)
        {
            if(visited[i] != -1) continue;
            if(DFS(i, visited, adj, i, s)) return true;
        }

        return false;
        
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
