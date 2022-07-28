// Link: https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1/

// Algorithm: Binary Search

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int point = INT_MAX;
    int left = 0, right = n-1;
    if(arr[0] == 1) return 0;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] == 1) 
        {
            point = min(point, mid);
            right = mid-1;
        }
        else
            left = mid + 1;
    }
    if(point == INT_MAX) point = -1;
    return point;
}