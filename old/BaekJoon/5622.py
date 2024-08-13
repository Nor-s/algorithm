dial = input()
su = 0

for d in dial:
    if d <= 'C':
        su += 3
    elif d <= 'F':
        su += 4
    elif d <= 'I':
        su += 5
    elif d <= 'L':
        su += 6
    elif d <= 'O':
        su += 7
    elif d  <= 'S':
        su += 8
    elif d <= 'V':
        su += 9
    else: 
        su += 10
print(su)


