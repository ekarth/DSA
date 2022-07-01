// Link: https://practice.geeksforgeeks.org/problems/max-length-chain/1/

#include<bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

bool comp(val a, val b)
{
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n)
{
    // same like longest increasing subsequence
    int max_len = 1;
    sort(p, p+n, comp);
    vector<int> dp(n, 1);
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(p[j].second < p[i].first)
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    max_len = *max_element(dp.begin(), dp.end());
    // for(auto i: dp) cout << i << " ";
    return max_len;
    
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        val p[n];
        for(int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
}
