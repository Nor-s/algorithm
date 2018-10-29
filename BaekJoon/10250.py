def ACM(H, W, N):
    w = (N-1)//H + 1
    h = (N-1)%H  +1 
    print('%d%02d' %(h, w))

T = int(input())
for i in range(T):
    H, W, N = map(int, input().split())
    ACM(H, W, N)