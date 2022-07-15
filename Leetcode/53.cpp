// Link: https://leetcode.com/problems/maximum-subarray/

// kadanes algorithm 

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int maxSubArray(vector<int>& nums) 
    {
        int max_so_far = INT_MIN, current_sum = 0;

        for(auto val: nums)
        {
            current_sum += val;
            max_so_far = max(max_so_far, current_sum);
            if(current_sum < 0) current_sum = 0;
        }

        if(current_sum) max_so_far = max(max_so_far, current_sum);
        return max_so_far;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution obj;
    cout << obj.maxSubArray(nums);
    return 0;
}