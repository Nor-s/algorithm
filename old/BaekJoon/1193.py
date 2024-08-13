a = int(input())
l ,i = 1,1
n ,m= 1,1
while a > l:
    i += 1
    l = i*(i+1) // 2
m = i
while l > a:
    m -= 1
    n += 1
    l -= 1
if i%2 == 0:
    print('{0}/{1}'.format(m,n))
else :
    print('{0}/{1}'.format(n,m))

