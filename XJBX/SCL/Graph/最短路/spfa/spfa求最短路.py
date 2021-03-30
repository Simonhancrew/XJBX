# 存储图的方式不太好，数据量大的时候会超时

if __name__=="__main__":
    n,m = map(int,input().split())
    g = [[] for _ in range(n + 1)]
    
    for i in range(m):
        a,b,c = map(int,input().split())
        g[a].append((b,c))

    INF = int(0x3f3f3f3f)
    d = [INF] * (n + 1)
    d[1] = 0
    st = [0] * (n + 1)
    st[1] = 1
    
    q = []
    q.append(1)
    while len(q) > 0:
        t = q.pop()
        st[t] = 0
        for node,w in g[t]:
            if d[node] > d[t] + w:
                d[node] = d[t] + w
                if st[node] == 0:
                    q.append(node)
                    st[node] = 1
        
        
    if d[n] == INF:
        print("impossible")
    else:
        print(d[n])