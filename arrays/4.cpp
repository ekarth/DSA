// Link: https://practice.geeksforgeeks.org/problems/common-elements1132/1/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> common;
            int i =0, j = 0, k = 0;
            while(i < n1 && j < n2 && k < n3)
            {
                if(A[i] == B[j] && B[j] == C[k])
                {
                    if(common.empty() || A[i] != common.back()) common.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                    continue;
                }
                int maxi = max(A[i],max(B[j], C[k]));
                if(A[i] < maxi) ++i;
                if(B[j] < maxi) ++j;
                if(C[k] < maxi) ++k;
            }
            if(common.size() == 0) common.push_back(-1);
            return common;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends
