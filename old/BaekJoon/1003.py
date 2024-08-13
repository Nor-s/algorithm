fib = [[0,1], [1,0], [0,1]]

countZero = 0
countOne = 0
# count Zero =  fib(n-1)
#count One = fib(n)
def f(n):
    if n in fib[0]:
        countZero = fib[1][n-1] + fib[1][n]
        countOne = fib[2][n-1] + fib[2][n]
        if not n+1 in fib[0]: 
            fib[0] = fib[0] + [n+1]
            fib[1] = fib[1] + [countZero]
            fib[2] = fib[2] + [countOne]
    else:
        f(n-1)
        f(n-1)

T = int(input())
for i in range(T):
    n = int(input())
    f(n)
    print(str(fib[1][n]), str(fib[2][n]))
        