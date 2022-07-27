// Link: https://practice.geeksforgeeks.org/problems/adding-array-element4756/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minOperations(int arr[], int n, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        int min_add = 0;

        while(pq.size() >= 1)
        {
            if(pq.top() >= k) break;
            int first = pq.top();
            pq.pop();
            if(pq.empty()) return -1;
            int second = pq.top();
            pq.pop();
            pq.push(first+second);
            min_add++;
        }
        return min_add;
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
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}