def fib(n: int) -> int:
    f = dict()
    for i in range(1, n+1):
        if i <= 2:
            f[i] = 1
            continue
        f[i] = f[i-1] + f[i-2]
        del f[i-2]
    answer = f[n]
    return answer

print(fib(8))