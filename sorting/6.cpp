// Link: https://practice.geeksforgeeks.org/problems/counting-sort/1

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255

class Solution{
    public:

    string countSort(string s)
    {
        vector<int> count(26, 0); // 26 alphabets
        
        for(auto ch: s) // count of each alphabet
        {
            count[ch-'a']++;
        }
        
        for(int i = 1; i < 26; i++) count[i]+= count[i-1]; // count of alphabets before it including count of itself
        
        string ans = s;
        
        for(int i = s.length()-1; i >= 0; i--)
        {
            char ch = s[i]; // alphabet to place to its correct position
            ans[count[ch-'a']-1] = s[i]; // position from count array and placing alphabet
            count[ch-'a']--; // decrement count of alphabets as one is placed
        }
        return ans;
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
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}