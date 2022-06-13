# Problem Statement:
# Given a triangle array, return the minimum path sum from top to bottom.
# For each step, you may move to an adjacent number of the row below. 
# More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

# Link: https://leetcode.com/problems/triangle/

# Solution taking O(n^2) space:
def minimumTotal(triangle) -> int:
    dp = [None for i in range(len(triangle))]
    for i in range(len(triangle)):
        dp[i] = [None for j in range(len(triangle[i]))]
    num_rows = len(dp)
    for i in range(num_rows-1, -1, -1):
        for j in range(i+1):
            if i == num_rows-1:
                dp[i][j] = triangle[i][j]
                continue
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1])
    print(dp)
    return dp[0][0]

# Solution taking O(n) space:
def minimumTotal(triangle) -> int:
    num_rows = len(triangle)
    dp = [None for i in range(len(triangle))]
    for i in range(len(triangle[num_rows-1])):
        dp[i] = triangle[-1][i]
    for row in range(num_rows-2, -1, -1):
        for i in range(row+1):
            dp[i] = triangle[row][i] + min(dp[i], dp[i+1])
        print(dp)
    return dp[0]
target = [[2],[3,4],[6,5,7],[4,1,8,3]]
print(minimumTotal(target))