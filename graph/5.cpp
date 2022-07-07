// Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Using Kruskal's Algorithm to form Minimum Spanning Tree and union-find method to detect cycle 

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    class edge // declaring edge class
    {
        
        public:
        int s, d, w;
        
        edge(int s, int d, int w)
        {
            this->s = s;
            this->w = w;
            this->d = d;
        }
    };
    
    static bool compare(edge a, edge b) // sorting edges in increasing order of edge weight
    {
        return a.w < b.w;
    }
    
    vector<int> parent; // defining parent vector
    
    int find_parent(int v) // function to find parent of the given vertex
    {
        if(parent[v] == v) return v;
        return(find_parent(parent[v]));
    }

	public:

	//Function to find sum of weights of edges of the Minimum Spanning Tree.

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int weight = 0;
        vector<edge> v; // vector to store edges

        for(int i = 0; i < V; i++)
        {
            parent.push_back(i); // initialising parent of vertices with itself 
            for(auto dest: adj[i])
            {
                if(dest[0] < i) continue; // destination vertex is less than source vertex, then we have already added its edge

                // dest[0]: destination
                // dest[1]: weight

                edge e(i, dest[0], dest[1]); // creating edge
                v.push_back(e);
            }
        }
        
        sort(v.begin(), v.end(), compare);

        int count = 0; // counting edges
        
        for(int i = 0; i < v.size(); i++)
        {
            int s = v[i].s;
            int d = v[i].d;
            int w = v[i].w;
            
            int par_s = find_parent(s);
            int par_d = find_parent(d);
            
            if(par_s == par_d) continue; // if both parents are same then adding edge will form cycle
            
            weight += w; // adding weight of the edge
            parent[par_s] = par_d; // updating parent of souorce to parent of destination (can also do vice-versa)

            count++; // increasing edge
            
            if(count == V-1) break; // if number of edges added is equal to numVertex-1, then MST is created and break out
        }

        return weight;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends