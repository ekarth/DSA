// Link: https://practice.geeksforgeeks.org/problems/20b8ec4db3f8da0697acdd3d54d9af9f76405443/1

#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b)
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }

    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        vector<pair<int,int>> pq; 
        vector<int> ans(k);
        
        for(auto num: arr)
        {
            int dist = abs(min(x-num, num-x));
            pq.push_back({dist, num});
        }
        
        sort(pq.begin(), pq.end(), compare);

        while(k--)
        {
            ans[k] = (pq[k].second);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
} 