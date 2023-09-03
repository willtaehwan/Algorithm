T = int(input())
cnt=0
for i in range(T):
    x1,y1,x2,y2 = map(int,input().split())
    st = int(input())
    for p in range(st):
        c1,c2,r = map(int,input().split())
        A = (x1-c1)**2+(y1-c2)**2
        B = (x2-c1)**2+(y2-c2)**2
        if A < r**2:
            if B > r**2:
                cnt += 1
        if A > r**2:
            if B < r**2:
                cnt += 1

    print(cnt)
    cnt=0