# 2D grid
# Start: top-left
# End: bottom-right
# movement: right and down
# No of ways to reach 

# for 1 row and 1 column grid, no. of ways to reach bottom right corner is 1

# Using memoization


# Using tabulation

def gridTraveler(n, m):
    ways = []
    for i in range(n+1):
        row = list()
        for j in range(m+1):
            row.append(0)
        ways.append(row)
    # ways = [[0 for i in range(m+1)] for j in range(n+1)]
    ways[1][1] = 1
    # print(ways[1][1])
    for i in range(1, n+1):
        for j in range(1, m+1):
            if i < n:
                ways[i+1][j] = ways[i+1][j] + ways[i][j]
            if j < m:
                ways[i][j+1] = ways[i][j+1] + ways[i][j]
    answer = ways[n][m]
    del ways
    return answer

print(gridTraveler(3,3))
print(gridTraveler(18,18))