// Link: https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1 

// Approach:
//     Since we have to find the smallest missing +ve element and the size is n
//     missing number should lie in domain [1,n+1].

//     In first loop:
//     whenever we encounter a +ve number we check that if number is in domain [1, n]. 
//     if number is in domain, we place it at its correct position (if the current number is duplicate then we don't place it and move on).
//     we swap the number with number at index number-1

//     At last, number n must be present at index n-1, n > 0

//     In second loop, we check if the number at index i doesn't equal to i+1, we return i+1 as it is the missing number.

//     if we don't find number in second loop then it means that all numbers in domain [1, n] are present. 
//     Hence, the smallest missing +ve number is n+1.

    
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > 0 && arr[i] <= n)
            {
                if(arr[arr[i]-1] != arr[i]) 
                {
                    // cout << i << " " << arr[i] << " " << arr[arr[i]-1] << endl;
                    swap(arr[i], arr[arr[i]-1]);
                    i--;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != i+1) return i+1;
        }
        return n+1;
    } 
};

int main() { 
    
    int t;
    cin>>t;
    while(t--)
    {
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends