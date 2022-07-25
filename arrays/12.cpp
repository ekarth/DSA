// Link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) 
{
    unordered_map<int, int> count;
    for(int i = 0; i < m; i++)
    {
        count[a2[i]]++;        
    }

    for(int i = 0; i < n; i++)
    {
        count[a1[i]]--;
    }

    for(auto it = count.begin(); it != count.end(); it++)
    {
        if(it->second > 0) return "No";
    }
    return "Yes";
}