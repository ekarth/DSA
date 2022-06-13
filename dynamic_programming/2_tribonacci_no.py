def tribonacci(n: int) -> int:
    tri = {}
    tri[0] = 0
    tri[1] = 1
    tri[2] = 1
    for i in range(3, n+1):
        tri[i] = tri[i-1] + tri[i-2] + tri[i-3]
        del tri[i-3]
    answer = tri[n]
    del tri
    return answer