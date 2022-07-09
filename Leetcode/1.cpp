// Link: https://leetcode.com/problems/two-sum/
// Question: 1. two sum 

// Time Complexity: O(N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if(m.count(x) > 0) return {m[x], i};
            m[nums[i]] = i;
        }
        
        return {};
    }
};

int main()
{
    return 0;
}