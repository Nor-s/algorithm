def isNotNested(ls):
    for i in range(len(ls)-1):
        if ls[i] in ls[i+1:]:
            return False
    return True

def substring(string, n, k):
    m = n//k
    tmp = []
    for i in range(k):
        tmp += [string[:m]]
        string = string[m:]
    return tmp

def lucidString(string, n, k, i):
    count = 0
    while i >= k:
        if  i%k ==0:
            m, j = 0, i
            while j != n+1:
                tmp= substring(string[m:j], i, k)
                if isNotNested(tmp):
                    print(tmp)
                    count=1+count 
                m +=1
                j += 1
        i -= 1
    return count
    

n, k = map(int, input().split())
string = input()

print(lucidString(string, n, k, n))