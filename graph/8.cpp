// Link: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/

// Approach: BFS as we have to find the minimum steps to move to target indices
// Knight can move in 8 directions
// visited array will check if the box is visited or not while maintaining the number of steps to reach there. 

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    public:

    bool isValid(int i, int j, int &N)
    {
        if(i >= 1 && j >= 1 && i <= N && j <=N) return true;
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
        vector<vector<int>> visited(N+1, vector<int>(N+1, -1));
        queue<vector<int>> q;
        q.push(KnightPos);
        visited[KnightPos[0]][KnightPos[1]] = 0;
        while(!q.empty())
        {
            if(q.front() == TargetPos)
            {
                break;
            }
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();

            for(int k = 0; k < 8; k++)
            {
                if(isValid(i+dx[k], j+dy[k], N) && visited[i+dx[k]][j+dy[k]] == -1)
                {
                    visited[i+dx[k]][j+dy[k]] = visited[i][j]+1;
                    q.push({i+dx[k], j+dy[k]});
                }
            }
        }
        return visited[TargetPos[0]][TargetPos[1]];
	}
};

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
    {
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);

		int N;
		cin >> N;

		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];

		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}