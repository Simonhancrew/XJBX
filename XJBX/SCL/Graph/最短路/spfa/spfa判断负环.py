if __name__=="__main__":
    n,m = map(int,input().split())
    g = [[] for _ in range(n + 1)]
    for i in range(m):
        a,b,c = map(int,input().split())
        g[a].append((b,c))
    q = []
    d = [0] * (n + 1)
    st = [0] * (n + 1)
    cnt = [0] * (n + 1)
    for i in range(1,n+1):
        q.append(i)
        st[i] = 1
    flag = 0
    while(len(q) > 0):
        t = q.pop()
        st[t] = 0
        for node,w in g[t]:
            if d[node] > d[t] + w:
                d[node] = d[t] + w
                cnt[node] = cnt[t] + 1
                if(cnt[node] >= n):
                    flag = 1
                    break
                if st[node] == 0:
                    q.append(node)
                    st[node] = 1
        if flag == 1:
            break
    if flag == 1:
        print("Yes")
    else:
        print("No")
