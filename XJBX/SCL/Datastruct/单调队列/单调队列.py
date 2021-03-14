if __name__=="__main__":
    q = []
    n,k = map(int,input().split())

    a = list(map(int,input().split()))

    for i in range(n):
        #检查队首元素有没有过期
        if q and q[0] < i - k + 1:
            q = q[1:]
        while q and a[q[-1]] >= a[i]:
            q.pop()
        q.append(i)
        if i >= k -1 :
            print(a[q[0]],end = ' ')

    print("")
    q = []
    for i in range(n):
        if q and q[0] < i - k + 1:
            q = q[1:]
        while q and a[q[-1]] <= a[i]:
            q.pop()
        q.append(i)
        if i >= k - 1:
            print(a[q[0]],end = ' ')