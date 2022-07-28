// Link: https://practice.geeksforgeeks.org/problems/count-the-zeros2550/1/

// Algorithm: Binary Search

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int countZeroes(int arr[], int n) {
        // code here
        int start = INT_MAX;
        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] == 0) 
            {
                start = min(start, mid);
                right = mid-1;
            }
            else left = mid+1;
        }
        if(start == INT_MAX) return 0;
        return n-start;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}