// Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Distance from the Source t each vertex using Bellman-Ford Algorithm.
// Given: No negative cycles are present

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:

    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V, 100000000);
        dist[S] = 0;
        for(int i = 0; i < V-1; i++)
        {
            for(auto edge: adj)
            {
                int s = edge[0], d = edge[1], wt = edge[2];
                if(dist[d] > dist[s]+wt) dist[d] = dist[s]+wt;
            }
        }
        return dist;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

