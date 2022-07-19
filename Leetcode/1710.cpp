// Link: https://leetcode.com/problems/maximum-units-on-a-truck/

// Approach:
//     Sort the boxTypes array in decreasing order of the number of units in a box 
//     Then for every box type, add the maximum units that can be loaded onto the truck until truckSize becomes 0.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        for(auto box: boxTypes)
        {
            if(truckSize == 0) break;
            int number_boxes = min(truckSize, box[0]);
            ans += number_boxes*box[1];
            truckSize -= number_boxes;
        }
        
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> boxTypes(n, vector<int>(2, 0));

        for(int i = 0; i < n; i++)
        {
            cin >> boxTypes[i][0] >> boxTypes[i][1];
        }

        int truckSize;
        cin >> truckSize;

        Solution obj;

        cout << obj.maximumUnits(boxTypes, truckSize) << endl;
    }
    
    return 0;
}