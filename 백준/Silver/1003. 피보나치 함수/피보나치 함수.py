N = [[1,0],[0,1]]
for i in range(2,41):
    N.append([0,0])
    if i > 1:
        N[i][0] = N[i-2][0] + N[i-1][0]
        N[i][1] = N[i-2][1] + N[i-1][1]

loop_num = int(input())
for i in range(loop_num):
    n = int(input())
    print(N[n][0],N[n][1])