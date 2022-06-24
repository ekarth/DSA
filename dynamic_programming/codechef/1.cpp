// Link: https://www.codechef.com/LP2TO306/problems/SUBINC

// DP
// Subproblems: Number of non-decreasing subarrays containing element at index 'i'
#include<bits/stdc++.h>
using namespace std;
long long countSubarrays(long long arr[], int n)
{
    long long count[n];
    count[0] = 1;
    long long total_count = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i-1]) // if non-dec then currnt element will be at the end of prev subarrays + 1 (as it is a subarray alone)
            count[i] = count[i-1] + 1;
        else // else it is the only subarray
            count[i] = 1;
        total_count += count[i];
    } 
    
    return total_count;

}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << countSubarrays(arr, n) << endl;
    }
    return 0;
}
