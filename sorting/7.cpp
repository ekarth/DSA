// Link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        vector<vector<int>> ans; // result
        int n = arr.size();

        sort(arr.begin(), arr.end()); // sort in increasing order

        for(int i = 0; i < n; i++)
        {
            // if current element is same as previous element then all the quadruples are already been added in the answer and 
            // processing it will only add duplicates in the ans 
            if(i > 0 && arr[i-1] == arr[i]) continue;
            for(int j = i+1; j < n; j++)
            {
                if(j > i+1 && arr[j-1] == arr[j]) continue; // same reason as that of the above loop element
                int l = j+1, r = n-1;
                int target = k - arr[i] - arr[j];
                
                while(l < r)
                {
                    int t = target-arr[l];
                    if(t == arr[r])
                    {
                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                        l++;
                        r--;
                        while(l < r && arr[l] == arr[l-1]) l++; // if current element and previous element are same then move forward
                        while(l < r && arr[r] == arr[r+1]) r--; // if current element and next element are same then move backward
                    }
                    else if(t > arr[r]) l++;
                    else r--;    
                }
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} 