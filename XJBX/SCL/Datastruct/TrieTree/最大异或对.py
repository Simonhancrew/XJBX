if __name__ == "__main__":
    n = int(input())
    N = n + 5
    M = 30 * N
    son = [[0,0] for _ in range(M)]
    idx = 0
    
    def insert(x):
        p = 0
        global idx
        for i in range(30,-1,-1):
            u = x >> i & 1
            if (son[p][u] == 0):
                idx += 1
                son[p][u] = idx
            p = son[p][u]
    
    def query(x):
        p = 0
        res = 0
        for i in range(30,-1,-1):
            u = x >> i & 1
            if(son[p][1-u] != 0):
               res = res * 2 + 1-u
               p = son[p][1- u]
            else:
                 res = res * 2 + u
                 p = son[p][u]
        return res 
    
    
    res = 0
    a = list(map(int,input().split()))
    for x in a :
        insert(x)
        t = query(x)
        res = max(res,x ^ t)
        
    print(res)