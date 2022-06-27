// Link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1/

// Algorithm: Boyer-Moore Majority Voting Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int votes = 1, candidate = a[0];
        for(int i = 1; i < size; i++)
        {
            if(a[i] == candidate) votes++;
            else votes--;
            if(votes == 0)
            {
                candidate = a[i];
                votes = 1;
            }
        }
        int count = 0;
        for(int i = 0; i < size; i++)
        {
            if(a[i] == candidate) count++;
            if(count > size/2) return candidate;
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
        Solution obj;
        cout << obj.majorityElement(a, n) << endl;
    }
    return 0;
}