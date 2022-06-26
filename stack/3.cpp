// Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/

#include<bits/stdc++.h>
using namespace std;
// Solution: 
// Store indices in stack
// If given cost is greater than equal to cost at s.top() index:
    // then while it is true; add the ans of top() index to current span and pop from stack
    

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack <int> s;
       vector<int> ans(n);
       s.push(0); // storing indices in stack
       ans[0] = 1;
       for(int i = 1; i < n; i++)
       {
           int count = 1;
           if(price[i] >= price[s.top()])
           {
               while(!s.empty() && price[i] >= price[s.top()])
               {
                   count += ans[s.top()];
                   s.pop();
               }
           }
           s.push(i);
           ans[i] = count;
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
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector<int> res = obj.calculateSpan(arr, n);
        for(int i: res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
