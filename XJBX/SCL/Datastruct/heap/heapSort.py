if __name__=="__main__":
    n,m = map(int,input().split())
    h = list(map(int,input().split()))
    size = n - 1
    def down(i):
        t = i
        if 2 * i  + 1<= size and h[2 * i + 1] < h[t]:
            t = 2 * i + 1
        if 2 * i + 2 <= size and h[2 * i + 2] < h[t]:
            t = 2 * i + 2 
        if t != i:
            h[i],h[t] = h[t],h[i]
            down(t)
    for i in range(n // 2,-1,-1):
        down(i)

    for i in range(m):
        print(h[0],end = ' ')
        h[size],h[0] = h[0],h[size]
        size -= 1
        down(0)