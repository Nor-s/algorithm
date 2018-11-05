def f (K, N):
    s = 0
    if K == 0:
        return N
    for i in range(1, N+1):
        s += f(K-1, i)
    return s

T = int(input())
for i in range(T):
    K = int(input())
    N = int(input())
    print(f(K, N))