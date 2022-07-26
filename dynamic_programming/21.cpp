// Link: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

// Approach:
//     Dynamic Programming
//     For each index, find the maximum height of the pole that lies in left and right by comparing it with the height of current pole.

//     To calculate water trapped: 
//         water trapped at index i is min(height of left or right pole) - height of current pole

#include<bits/stdc++.h>
using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long water = 0;

        vector<int> left_pole(n), right_pole(n);
        left_pole[0] = arr[0], right_pole[n-1] = arr[n-1];
        for(int i = 1; i < n; i++)
        {
            left_pole[i] = max(left_pole[i-1], arr[i]);
            right_pole[n-1-i] = max(right_pole[n-i], arr[n-1-i]);
        }

        for(int i = 0; i < n; i++)
        {
            water += (min(left_pole[i], right_pole[i]) - arr[i]);
        }
        
        return water;
    }
};

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++)
        {
            cin >> a[i];            
        }
        Solution obj;
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  