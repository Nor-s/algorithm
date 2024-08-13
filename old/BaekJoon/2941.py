dic = ["c=", "c-" , "dz=" ,"d-" , "lj" ,"nj" , "s=","z="]
a = input()

for c in dic:
    a=a.replace(c,'1')
print(len(a))