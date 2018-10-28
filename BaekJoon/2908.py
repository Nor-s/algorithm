def F(n,m):
    m = m+n%10
    n = n//10
    if n != 0:
        return F(n, 10*m)
    return m


a, b = map(int, input().split())

a = F(a,0)
b = F(b, 0)
print(max(a,b))

print(max((int(x[::-1]) for x in input().split())))