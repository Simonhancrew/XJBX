if __name__=="__main__":
    n,m,k = map(int,input().split())
    INF = int(0x3f3f3f3f)
    dist = [INF] * (n + 1)
    backup = [INF] * (n + 1)
    edge = [[0,0,0] for _ in range(m)]
    
    for i in range(m):
        edge[i][0],edge[i][1],edge[i][2] = map(int,input().split())
    
    
    dist[1] = 0

    for i in range(k):
        #注意深拷贝
        backup = dist[:]
        for j in range(m):
            a,b,w = edge[j][0],edge[j][1],edge[j][2]
            dist[b] = min(dist[b],backup[a] + w)
    
    if dist[n] > INF // 2:
        print("impossible")
    else:
        print(dist[n])