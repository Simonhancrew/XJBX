if __name__ == "__main__":
    n, m = map(int, input().split())
    q = [[0, 0]]
    g = []
    d = [[-1] * m for _ in range(n)]
    d[0][0] = 0
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    def bfs():
        while len(q) > 0:
            t = q[0]
            q.pop(0)
            for i in range(4):
                x = t[0] + dx[i]
                y = t[1] + dy[i]
                if x >= 0 and y >= 0 and x < n and y < m and g[x][y] == 0 and d[x][y] == -1:
                    d[x][y] = d[t[0]][t[1]] + 1
                    q.append([x,y])
        return d[n - 1][m - 1]


    for i in range(n):
        #记得输入变成int
        g.append(list(map(int,input().split())))
    print(bfs())