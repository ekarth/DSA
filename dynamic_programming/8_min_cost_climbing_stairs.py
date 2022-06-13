def min_cost_finder(cost):
    cost.append(0) # added as the top of stair has 0 cost and if we come directly from n-2 th step with min cost, it helps.
    min_cost = [0] * (len(cost) + 1) # min cost associated with each step
    min_cost[1] = cost[0] # base case: min cost to go to step 1
    for i in range(2, len(min_cost)):
        min_cost[i] = min(min_cost[i-2], min_cost[i-1]) + cost[i-1]
    print(min_cost)
    return min_cost[len(cost)]

print(min_cost_finder([1,100,1,1,1,100,1,1,100,1]))