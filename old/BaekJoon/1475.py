a = [0]*10
i = input()
for j in i:
    a[int(j)] += 1
a[6] =(a[6] + 1+ a[9])//2
print(max(a[:9]))
