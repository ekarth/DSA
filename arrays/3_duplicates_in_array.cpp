// Problem Link: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1/

// Time Compexity: O(n)
// Space Compexity: O(n)

#include<bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n) {
    // code here
    vector<int> freq(n, 0);
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    vector<int> answer;
    for(int i = 0; i < n; i++)
    {
        if(freq[i] > 1) answer.push_back(i);
    }
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}
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
        vector<int> ans = duplicates(a, n);
        for(int i: ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

