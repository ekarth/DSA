// Link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    int partition(int arr[], int l, int r)
    {
        int pivot = arr[r]; // last element as pivot element

        // left: number of elements less then the pivot element
        int left = l, right = r-1;
        while(left <= right)
        {
            if(arr[left] <= pivot) left++;
            else 
            {
                // if current element is greater than pivot element, then swap it 
                swap(arr[left], arr[right]);
                // cout << "No" << left << right << endl;
                right--;
                
            }
        }
        // At last swap the element at left index eith pivot element
        swap(arr[r], arr[left]);
        return left;
    }

    int kthSmallest(int arr[], int l, int r, int k) {

        if(l <= r)
        {
            int p = partition(arr, l, r);

            if(p == k-1) return arr[p];
            int ans;

            // if pivot index is greater than k-1 index than look in the left part of the array
            if(p >= k)
            {
                ans = kthSmallest(arr, l, p-1, k);
                if(ans != -1) return ans;
            }

            // else look in right part of the array
            else 
            {
                ans = kthSmallest(arr, p+1, r, k);
                if(ans != -1) return ans;
            }
        }
        return -1;
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
        int a[n];
        
        for(int i = 0; i < n; i++) cin >> a[i];
            
        int k;
        cin >> k;

        Solution ob;
        cout << ob.kthSmallest(a, 0, n-1, k) << endl;
    }
    return 0;
}