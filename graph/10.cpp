// Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/

// Once a vertex is visited, then its shortes path is already been found. 
// Using this concept, and using priority queue to find best next node Lazy Dijkstra is implemented below

#include<bits/stdc++.h>
using namespace std;

class Solution
{

    struct compare // comparartor function for min priority queue using distance(2nd value of pair)
    {
        constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b) const noexcept
        {
            return a.second > b.second;
        }
    };

	public:

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<bool> visited(V, false); // to check if a node is visited or not
        vector<int> distance(V, INT_MAX); // distance to each node from starting node

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        distance[S] = 0; // dist of starting node to itself is 0;
        pq.push({S, 0});

        while(!pq.empty())
        {
            int node = pq.top().first;
            int dist = pq.top().second;
            pq.pop();

            if(visited[node]) continue; 
            visited[node] = true;

            if(distance[node] < dist) continue;

            for(auto x: adj[node])
            {
                int neighbor = x[0];
                int weight = x[1];

                // cout << node <<  ' ' << neighbor << ' ' << weight << endl;

                int current_distance = distance[node] + weight;
                if(distance[neighbor] > current_distance)
                {
                    distance[neighbor] = current_distance; // updating distance
                    pq.push({neighbor, current_distance}); // pushing in queue
                }
            }
        }
        return distance;
    }
};

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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends