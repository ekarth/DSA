// Link: https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1

#include<bits/stdc++.h>
using namespace std;

// Since Time complexity is O(logN) and the array is sorted, Binary Search is the best approach

// Also since only one element is coming once and all the other elements are coming twice, index of arrays can tell us where to
// search for the single element.

// if current element and previous element are same than, we check for the index of the previous element 
    // if its an odd index than it means that there are odd number of elements before it hence the single element lies in that region 
    // else if index is even than it means that the single element lies in the other (right) part of the array.

// if current element and next element are same than, we check for the index of the current element 
    // if its an odd index than it means that there are odd number of elements before it heance the single element lies in that region 
    // else if index is even than it means that the single element lies in the other (right) part of the array.  
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int ans;
        int l = 0, r = n-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            
            if(mid > 0 && arr[mid] == arr[mid-1])
            {
                if((mid-1)%2 == 1)
                {
                    r = mid-2; // left region
                }
                else 
                {
                    l = mid+1; // right region
                }
            }
            else if(mid < r && arr[mid] == arr[mid+1])
            {
                if(mid%2 == 1)
                {
                    r = mid-1; // left region
                }
                else
                {
                    l = mid+2; // right region
                }
                
            }
            else 
            {
                ans = arr[mid];
                break;
            }
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
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}