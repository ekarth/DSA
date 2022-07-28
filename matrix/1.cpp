// Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// Approach:
    // Let 0 be celebrity
    // if celebrity knows anyone then we make the known person as new celebrity

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:

    int celebrity(vector<vector<int> >& M, int n) 
    {
        int celeb = 0;
        for(int i = 1; i < n; i++) if(M[celeb][i]) celeb = i;
        for(int i = 0; i < n; i++)
        {
            // celebrity knows someone then he is not a celebrity and no one in party is celebtity
            // if celebrity don't know i, where i is not same as celebity and inturn i also dont celebrity,
            // then no one knows one another, hence there is no celebrity in party.
            if(M[celeb][i] == 1 || (M[celeb][i] == 0 && i != celeb && M[i][celeb] != 1)) return -1;
        }

        return celeb;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}