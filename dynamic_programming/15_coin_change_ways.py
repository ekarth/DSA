# link: https://leetcode.com/problems/coin-change-2/

# Description:
# Given the amount and the different denominations, find the number of ways in which denominations can sum upto amount.

# Solution:
# Type: DP
# Subproblem: 
# Check if the current denomination will be the part of the transaction or not,
# if yes, then we will subtract the denomination from the target and keep the denomination array as such
# if no then we will keeep the target as such but will discard the current denomination from the denomination array

# Base Case: 
# if number of denominations == 0, then return 0
# if target == 0, then return 1



def change_helper(amount, coins, dp):
    if len(coins) == 0:
        return 0
    if amount == 0: 
        dp[len(coins)-1][0] = 1
        return 1
    if amount < 0:
        return 0
    if dp[len(coins)-1][amount] != None:
        return dp[len(coins)-1][amount]
    part_of_trans = change_helper(amount-coins[0], coins, dp)
    not_part_of_trans = change_helper(amount, coins[1:], dp)
    dp[len(coins)-1][amount] = part_of_trans+not_part_of_trans
    return dp[len(coins)-1][amount]
def change(amount, coins) -> int:
    dp = [[None for i in range(amount+1)] for i in range(len(coins))]
    change_helper(amount, coins, dp)
    # print(dp)
    return dp[-1][-1]

print(change(5, [1,2,5]))
print(change(3, [2]))
print(change(10, [10]))
    
# Furthur optimization:
# Use O(n) Space
# Use O(nm) Time

# GFG Link: https://practice.geeksforgeeks.org/problems/coin-change2448/1
# Bottom-up Approach 
# O(n) space 
def count(self, S, m, n): 
    # code here 
    amount = n
    num_coins = m
    dp = [0]*(amount+1)
    dp[0] = 1
    for i in range(num_coins): # (O(m))
        for sum in range(S[i], amount+1): # O(n)
            if sum - S[i] >= 0:
                dp[sum] += dp[sum-S[i]]
    
    return dp[-1]