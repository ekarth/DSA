// Link: https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) 
    {
	    // code here
        
        //odd index peak element
	    for(int i = 1; i < n; i++)
	    {
	        // if smaller element is present at odd index then swap
	        if(arr[i] < arr[i-1] && (i%2) != 0) swap(arr[i],arr[i-1]);
	        
	        // if larger element is present at even index then swap
	        if(arr[i] > arr[i-1] && (i%2) == 0) swap(arr[i], arr[i-1]);
	    }
	}
};

//{ Driver Code Starts.

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
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends