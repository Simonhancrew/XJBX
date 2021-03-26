if __name__=="__main__":
    n,m = map(int,input().split())
    #h是我要构建的邻接表
    h = [[] for _ in range(n + 10)] 
    #distance
    d = [-1] * (n + 10)
    #宽搜队列
    q = []

    def add(a,b):
        h[a].append(b)
    #宽搜模板
    def bfs(q,n):
        q.append(1)
        d[1] = 0
        while q:
            t = q[0]
            q = q[1:]
            for node in h[t]:
                if(d[node] == -1):
                    d[node] = d[t] + 1
                    q.append(node)
        return d[n]

    for i in range(m):
        a,b = map(int,input().split())
        add(a,b)
    
    print(bfs(q,n))