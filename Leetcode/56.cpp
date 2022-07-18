// Link: https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0]; // sort in increasing order of start values of intervals
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> ans;

        // Initailise start and end variables by first interval values
        int start = intervals[0][0]; 
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)
        {
            // if start of interval is less than equal to the end of the ongoing interval then add the current interval into the 
            // ongoing interval and change end to be the maximum of both interval end values.
            if(intervals[i][0] <= end) end = max(end, intervals[i][1]);

            // else add the ongoing interval to the ans and set start and end variables to current interval's values
            else 
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }

            // push the values of ongoing interval on reaching last interval 
            if(i == intervals.size()-1)
            {
                ans.push_back({start, end});
            }
        }

        // intervals.size() == 1 add the start and end values of the only interval present
        if(ans.size() == 0) ans.push_back({start, end});

        return ans;
    }
};
int main()
{
    // vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals = {{1,4}, {2,3}};

    Solution obj;
    vector<vector<int>> ans = obj.merge(intervals);

    for(auto i: ans)
    {
        for(auto j: i) cout << j << " ";
        cout << endl;
    }

    return 0;
}