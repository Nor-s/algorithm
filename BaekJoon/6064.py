def f(M, N, X, Y, x, y, count, lim):
    while Y != y:
        y=(y+M-1)%N+1
        count = count + M
        if lim < count:
            return -1
    return count

def m(M,N,x,y,count):
    while y != 1 or count==1: 
        y=(y+M-1)%N+1
        count = count + M
    return count

T = int(input())
for i in range(T):
    M, N, x, y = map(int, input().split(' '))
    lim = m(M,N,1,1,1) 
    print(f(M, N, x, y, x, (x-1)%N+1, x, lim))