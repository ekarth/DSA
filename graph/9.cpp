// Link: https://practice.geeksforgeeks.org/problems/topological-sort/1/

// Approach: 
    // for each unvisited vertex, find the unvisited nodes that can be traced through it using DFS
    // after finding these nodes store them in reverse order 
    // do this step till all nodes of graph are not visited

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    
	public:
	//Function to return list containing vertices in Topological order. 
    void DFS(int v, vector<int> adj[], vector<bool> &visited, vector<int> &nodesTraversed)
    {
        if(visited[v]) return;
        visited[v] = true;

        for(auto neighbor: adj[v])
        {
            DFS(neighbor, adj, visited, nodesTraversed); // going to every neighbor
        }
        // adding after to store them in reverse order (call stack)
        nodesTraversed.push_back(v); // Adding node to traverse list
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<bool> visited(V, false);
        vector<int> ans(V);

        for(int i = 0; i < visited.size(); i++)
        {
            if(visited[i]) continue;

            vector<int> nodesTraversed; // store nodes that are traversed during a DFS call
            DFS(i, adj, visited, nodesTraversed);

            for(auto node: nodesTraversed)
            {
                ans[--V] = node; // Adding them to ans
            }
        }
        return ans;
	}
};


/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  