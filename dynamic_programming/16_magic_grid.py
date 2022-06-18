# Problem Statement:
# You are given a magic grid A with R rows and C columns. 
# In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, 
# or poison, which takes away |A[i][j]| strength points. 
# If at any point of the journey, the strength points become less than or equal to zero, then you will die.
# You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). 
# From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and 
# you can not move outside the magic grid. You have to find the minimum number of strength points with which 
# you will be able to reach the destination cell.
def min_health_finder(r, c, grid):
    # Creating table 
    dp = [[0 for i in range(c)] for j in range(r)]

    # Entering Base Cases:
    if grid[r-1][c-1] < 0:
        dp[r-1][c-1] = 1-grid[r-1][c-1]
    else:
        dp[r-1][c-1] = 1

    # Filling last row of dp matrix
    for i in range(c-2, -1, -1):
        dp[r-1][i] = max(1, dp[r-1][i+1] - grid[r-1][i])

    # Filling last column of dp matrix:
    for i in range(r-2, -1, -1):
        dp[i][c-1] = max(1, dp[i+1][c-1] - grid[i][c-1])

    # Filling enteries using bottom-up approach:
    for i in range(r-2, -1, -1):
        for j in range(c-2, -1, -1):
            dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j]) - grid[i][j]) # Min value should be 1

    # print(dp)
    return dp[0][0]

def main():
    test = int(input())
    while test != 0:
        r,c = [int(x) for x in (input().split())]
        grid = []
        for i in range(r):
            grid.append([int(x) for x in input().split()])
        # print(grid)
        print("Answer:", min_health_finder(r, c, grid))
        test -= 1

if __name__ == "__main__":
    main()