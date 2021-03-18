if __name__=="__main__":
    n,m = map(int,input().split())
    p = [i for i in range(n+1)]
    size = [1] * (n + 1)
    
    def find(x):
        if x != p[x]:
            p[x] = find(p[x])
        return p[x]
        
    for i in range(m):
        ii = input().split()
        if ii[0] == 'C':
            a,b = int(ii[1]),int(ii[2])
            if find(a) == find(b):
                continue
            size[find(b)] += size[find(a)]
            p[find(a)] = find(b)
        elif ii[0] == "Q1":
            a,b = int(ii[1]),int(ii[2])
            if find(a) == find(b):
                print("Yes")
            else:
                print("No")
        else:
            a = int(ii[1])
            print(size[find(a)])