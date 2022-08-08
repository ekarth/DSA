// Link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

	long long maxProduct(vector<int> arr, int n) 
    {
        long long min_ending_here = arr[0];
	    long long max_ending_here = arr[0];

        long long ans = arr[0];
        for(int i = 1; i < n; i++)
        {
            // temp to store the maximum element that will end here
            long long temp = max((long long)arr[i], max(arr[i] * max_ending_here, arr[i] * min_ending_here));
            min_ending_here= min((long long)arr[i], min(arr[i] * max_ending_here, arr[i] * min_ending_here));

            max_ending_here = temp;
            ans = max(ans, max_ending_here);
        }
        return ans;
    }
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}