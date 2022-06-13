
d = [40, 20, 30, 10, 30]
# d = [2, 3, 4, 2]
dp = [[None for i in range(len(d) - 1)] for j in range(len(d) - 1)]
for i in range(len(d)-1):
    dp[i][i] = 0
print(dp)
def minimum_multiplications(i, j):
    # print(i, j)
    if dp[i][j] != None:
        return dp[i][j]
    all_costs = []
    for k in range(i, j):
        dp[i][k] = minimum_multiplications(i, k)
        dp[k+1][j] = minimum_multiplications(k+1, j)
        cost = d[i-1]*d[k]*d[j]
        all_costs.append(dp[i][k] + dp[k+1][j] + cost)
        # print(all_costs)
    dp[i][j] = min(all_costs)
    return dp[i][j]

print(minimum_multiplications(0, len(d)-2))

