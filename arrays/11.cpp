// Link: https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        if(n == 1) return 1;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        long long sum_so_far = 0;

        for(int i = 1; i < n; i++)
        {
            // cout << sum << " ";
            sum -= a[i-1];
            sum_so_far += a[i-1];
            if(sum-a[i] == sum_so_far) return i+1;
        }

        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends