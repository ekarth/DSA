# Bitonic Subarray: Array in which the values are arranged first in strictly ascending order and then in strictly descending order.
# A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
# LBS: Largest Bitonic Subarray

def lengthOfLDS(sequence):

    dp = [1] * len(sequence)
    for i in range(len(sequence)-2, -1, -1):
        for j in range(i+1, len(sequence)):
            if sequence[i] > sequence[j]:
                dp[i] = max(dp[i], dp[j]+1)
    # print(dp)
    return dp

def lengthOfLIS(sequence):

    dp = [1] * len(sequence)
    for i in range(1, len(sequence)):
        for j in range(0, i):
            if sequence[i] > sequence[j]:
                dp[i] = max(dp[i], dp[j]+1)
    return dp

def lengthLBS(sequence):
    '''Input: sequence of numbers
    Output: length of the largest bitonic subarray'''
    inc = lengthOfLIS(sequence) # returns list containing max length of increasing sequence at each index
    dec = lengthOfLDS(sequence) # returns list containing max length of decreasing sequence at each index
    answer = -1
    for i in range(len(inc)):
        answer = max(answer, inc[i]+dec[i]-1) 
    # 1 is subtracted as the number itself will be counted twice one while increasing seq and one while dec seq
    return answer

print(lengthLBS([9,8,1,7,6,5,4,3,2,1]))

