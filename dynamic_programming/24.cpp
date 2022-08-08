// Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.

    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<int> dp(W+1, 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = W; j >= wt[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
            }
        }
        
        return dp[W];
    }
};

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++) cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++) cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}