# find the longest increasing subsequence ending at each index
# to find longest increasing subsequencs ending at index i, we need to find out for all the index less than i
# that what is the longest increasing subsequencs ending at that index.
# if the number at that index is less than the number at index i, then we will add +1 to that number and take their max to enter at i.

# Link: https://leetcode.com/problems/longest-increasing-subsequence/
def lengthOfLIS(sequence):
    '''Input: sequence of numbers
    Output: length of the longest increasing subsequence
    longest increasing subsequence: Each number is followed by a larger number'''
    dp = [1] * len(sequence)
    for i in range(1, len(sequence)):
        for j in range(0, i):
            if sequence[i] > sequence[j]:
                dp[i] = max(dp[i], dp[j]+1)
    print(dp)
    answer = max(dp)
    del dp
    return answer

print(lengthOfLIS([2,1,3,4,9,7,8]))
# time complexity: O(n^2)
# space complexity: O(n)