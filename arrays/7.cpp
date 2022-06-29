// Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

#include<bits/stdc++.h>
using namespace std;

// Approach: 
//      Since all the numbers are greater than 1, it is easy to arrange each element using indices
//      s.t. each element should be 1 greater than the index.
//      This can easily be done by swapping by swapping the number with the number at its correct postion.
//      Whenever we found an exception, we update missing and repeating number.
//      Time Complexity: O(2*n) = O(n)
//      Space Complexity: O(1)

class Solution{
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        int i = 0;
        for(int i = 0; i < n; i++)
        {
            // cout << i << " " << arr[i] << endl;
            if(arr[i]-1 == i)   continue;
            while(arr[i] != arr[arr[i] -1])
                swap(arr[i], arr[arr[i] - 1]);
            
            if(arr[i]-1 != i)
            {
                ans[1] = i+1;
                ans[0] = arr[i];
            }
        }
        return ans;
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
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        Solution obj;
        auto ans = obj.findTwoElement(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}