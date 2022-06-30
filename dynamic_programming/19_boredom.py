# Gary is bored and wants to play an interesting but tough game . 
# So he figured out a new board game called "destroy the neighbours" . 
# In this game there are N integers on a board. 
# In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed.
# This move will give him x points.
# He plays the game until the board becomes empty.
# But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off. 
# Can you help Gary in finding out the maximum points he receive grab from the game ?


# Subproblem: calculate the contribution of each number and check if we want to pick this number
## picking a number: max(contribution of present number + contribution till i-2, contribution till i-1)

def maximum_pts(a):

    contribution = [0] * (max(a)+1)

    for element in a:
        contribution[element] += element

    print(contribution)
    dp = {}
    dp[0] = contribution[0]
    dp[1] = contribution[1]

    for i in range(2, len(contribution)):
        dp[i] = max(dp[i-1], (dp[i-2] + contribution[i]))

    return dp[len(contribution)-1]

print(maximum_pts([1,2,1,2,3,4,10,18]))

