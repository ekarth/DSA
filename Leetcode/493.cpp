// Link: https://leetcode.com/problems/reverse-pairs/
// Question: 493. Reverse Pairs

// Approach: merge sort as we have to compare all the pairs while maintaining the order 

// Time Complexity: O(NlogN) + O(N) + O(N) mergesort + counting pairs + merge 
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int> &nums, int left, int mid, int right)
    {
        // merge function which merge two sorted arrays
        int count = 0;
        int l = left, r = mid+1;
        int k = 0;
        int temp[right-left+1];

        // counting revrse pairs
        
        for(int l = left; l <= mid; l++) //for every element in first array we find how many elements of second array can be paired 
        {
            while(r <= right && nums[l] > 2*long(nums[r]))
            {
                r++;
            }
            count += r-(mid+1); // adding the pairs to count variable
        }

        r = mid+1;
        l = left;

        // Putting elements of both arrays in sorted order in temp array
        while(l <= mid && r <= right)
        {
            if(nums[l] < nums[r]) temp[k++] = nums[l++];
            else temp[k++] = nums[r++];
        }

        while(l <= mid) temp[k++] = nums[l++];
        while(r <= right) temp[k++] = nums[r++];

        // reflecting changes in initial array
        while(k--)
        {
            nums[right--] = temp[k];
        }
        
        return count;
    }
    
    int mergesort(vector<int> &nums, int left, int right)
    {
        // function that divides the given arrays into left and right part 
        int count = 0;
        if(left < right)
        {
            int mid = left + (right-left)/2;
            count += mergesort(nums, left, mid);
            count += mergesort(nums, mid+1, right);
            count += merge(nums, left, mid, right);
        }
        
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        return mergesort(nums, left, right);
        
    }
};

int main()
{
    int n = 5;
    
    vector<int> nums{1,2,3,5,6,2,1};
    Solution obj;
    cout << obj.reversePairs(nums);
    return 0;
}