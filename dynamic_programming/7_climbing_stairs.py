def ways_to_climb(n):
    ways = [0] * (n+1)
    ways[1] = 1
    ways[0] = 1
    for i in range(2, n+1):
        ways[i] = ways[i-1] + ways[i-2]
    print(ways)
    return ways[n]
print(ways_to_climb(5))