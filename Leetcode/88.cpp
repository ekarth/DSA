// Link: https://leetcode.com/problems/merge-sorted-array/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(M+N)
// Space Complexity: O(1) in-place (main objective)

// Approach:
    // Place the largest element of both the arrays to the end of first array 
    // same as that of mergesort but inplace 
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m-1, j = n-1, k = m+n-1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }

        while(j >= 0) nums1[k--] = nums2[j--];
    }
};

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    Solution obj;

    obj.merge(nums1, 3, nums2, nums2.size());

    for(auto ele: nums1)
    {
        cout << ele << " ";
    }
    return 0;
}