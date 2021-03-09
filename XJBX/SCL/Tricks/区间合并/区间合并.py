if __name__ == "__main__":
    n = int(input())
    q = []
    for i in range(n):
        l,r  = map(int,input().split())
        q.append([l,r])
        
    def pcom(x,y):
        return x[0] < y[0]
    q= sorted(q,key = lambda y:y[0])
    res = 1
    l,r = q[0][0],q[0][1]
    for i in range(1,n):
        if r < q[i][0]:
            l = q[i][0]
            r = q[i][1]
            res += 1
        else:
            r = max(r,q[i][1])
    print(res)