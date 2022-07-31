// Link: https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1?page=1

// Time to build heap from an unsorted array: O(N)
// using heapsort

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
    void heapify(int arr[], int k, int n)
    {
        // cout << k << " ";
        int l = 2*k+1, r = 2*k+2; // left and right child indices
        int largest = k;
        if(l < n && arr[k] < arr[l]) largest = l;
        if(r < n && arr[largest] < arr[r]) largest = r;

        if(largest != k)
        {
            swap(arr[k], arr[largest]);
            heapify(arr, largest, n);
        }
    }
	vector<int> kLargest(int arr[], int n, int k) 
    {
	    //building max heap
        for(int i = n/2; i >= 0; i--)
        {
            heapify(arr, i, n);
        }
        
        vector<int> ans;
        
        // heapsort
        for(int i = n-1; k > 0; i--, k--)
        {
            swap(arr[0], arr[i]);
            ans.push_back(arr[i]);
            heapify(arr, 0, i);
        }

        return ans;
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}