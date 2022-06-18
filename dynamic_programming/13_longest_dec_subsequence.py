def lengthOfLDS(sequence):
    '''Input: sequence of numbers
    Output: length of the longest decreasing subsequence
    longest decreasing subsequence: Each number is followed by a smaller number'''
    dp = [1] * len(sequence)
    for i in range(len(sequence)-2, -1, -1):
        for j in range(i+1, len(sequence)):
            if sequence[i] > sequence[j]:
                dp[i] = max(dp[i], dp[j]+1)
    # print(dp)
    answer = max(dp)
    del dp
    return answer

print(lengthOfLDS([10, 22, 9, 33, 21, 50, 41, 60, 80, 3]))