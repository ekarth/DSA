# Given target number and list of numbers, find if sum of numbers from list can make target.
# All numbers are positive 
# bottom-up approach DP
def canSum(target, numbers):
    dp = [False] * (target+1)
    dp[0] = True
    for i in range(target+1):
        if dp[i]:
            for num in numbers:
                if i + num <= target:
                    dp[i+num] = True
        # print(dp)
        if dp[target]:
            return True
    return False

print(canSum(7, [3,5,4]))
print(canSum(300, [7, 14]))