// Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int n, int arr[], int sum)
    {
        if(sum < 0) return 0;
        if(sum == 0) return 1;
        if(n == 0) return 0;

    }
    int equalPartition(int n, int arr[])
    {
        int sum = accumulate(arr, arr+n, 0);
        if(sum % 2 != 0) return 0;
        sum = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));

        for(int i = 0; i <= sum; i++) dp[0][i] = false;
        for(int i = 0; i <= n; i++) dp[i][0] = true; 

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j < arr[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }

        return dp[n][sum];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}