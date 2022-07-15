// Link: https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:

    void nextPermutation(vector<int>& nums) 
    {
        
        int ind1 = -1;

        // find the first value which is less than its next value while traversing from the end 
        for(int i = nums.size()-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind1 = i;
                break;
            }
        }
        
        // if we find ind1 then it means that the given vector has the next permutation and its elements are not in decreasing order 
        if(ind1 != -1)
        {
            int ind2 = -1;
            int ans = INT_MAX;

            // we find the index of element which is the next greater element preent at index ind1
            for(int i = nums.size()-1; i > ind1; i--)
            {
                if(nums[i] > nums[ind1] && nums[i] < ans)
                {
                    ans = nums[i];
                    ind2 = i;
                }     
            }

            // we swap ind1 and ind2 elements
            swap(nums[ind1], nums[ind2]);   
        }

        int l = ind1+1, r = nums.size()-1;

        // we reverse all the elements right of ind1 index.
        // id ind1 = -1, that means that the vector is in decreasing (not strictly) order, so it should be the present last in the
        // lexographical order of permutations array. So, in this case we reverse entire array.
        while(l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};
int main()
{
    // vector<int> nums = {1,3,4,3,2};
    vector<int> nums = {3,2,1};
    Solution obj;
    obj.nextPermutation(nums);

    for(auto i: nums) cout << i << " ";
    return 0;
}