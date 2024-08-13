import math

def f():
    x, y = map(int,input().split())
    count = 0
    d = int(y) - int(x)
    i = int(math.sqrt(d))
    l = i*(i+1)
    count = i*2
    d=d-l
    count += d//i
    if d%i != 0:
        count+=1
    return count
T = int(input())
for i in range(T):
    print(f())