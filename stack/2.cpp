// Link: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        vector<long long> ans(n, 0);
        ans[n-1] = -1;
        s.push(arr[n-1]);
        for(int i = n-2; i >= 0; i--)
        {
            // if num < s.top() then s.top() is the next greater element of num
            if(arr[i] < s.top()) 
                ans[i] = s.top();
            else 
            {
                // while s.top() <= num, we will pop from stack
                while(!s.empty())
                {
                    if(s.top() <= arr[i]) s.pop(); 
                    else break;
                }
                // if no element in stack was greater than num, -1
                if(s.empty()) 
                    ans[i] = -1;
                else 
                    ans[i] = s.top();
                
            }
            s.push(arr[i]);    
        }
        return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for(long long i: res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
