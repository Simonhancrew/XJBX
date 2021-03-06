if __name__ == "__main__":
    m,n = map(int,input().split())
    
    a = list(map(int,input().split()))
    
    b = [0] * (m + 10)
    
    def insert(l,r,c):
        b[l] += c
        b[r + 1] -= c
    
    for i in range(m):
        insert(i+1,i+1,a[i])
    
    
    for i in range(n):
        l,r,c = map(int,input().split())
        insert(l,r,c)
    
    for i in range(1,m + 1):
        b[i] += b[i - 1]
    for i in range(1,m+1):
        print(b[i],end = ' ')