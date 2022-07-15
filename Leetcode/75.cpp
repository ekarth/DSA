// Link: https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) => 1 pass only. We can also perform the same operations using two passes, first for counting how many times 
// each element comes and second to fill the array accordingly.

// Space Complexity: O(1) (in-place) 

// Approach: 
//     3 pointers low, mid, high
//     in every step check the element present at mid;
//         if 0, then swap elements at low and mid, increment both
//         if 1, increment mid 
//         if 2, then swap elements at high and mid, decrement high

//     So, in each step we are decreasing the size of problem by 1

class Solution 
{
public:

    void sortColors(vector<int>& nums) 
    {
        int low = 0, mid = 0, high = nums.size()-1;
        while(high >= 0 && nums[high] == 2) high--;
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    vector<int> nums = {2};

    Solution obj;
    obj.sortColors(nums);

    for(int color: nums) cout << color << " ";
    return 0;
}