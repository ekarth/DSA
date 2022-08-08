// Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1));

        for(int i = 0; i <= sum; i++) dp[0][i] = false;
        for(int i = 0; i <= arr.size(); i++) dp[i][0] = true;

        for(int i = 1; i <= arr.size(); i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j < arr[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }

        return dp[arr.size()][sum];
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 