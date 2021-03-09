if __name__ == "__main__":
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    
    j = 0
    
    for i in range(m):
        if j == n:
            break
        if a[j] == b[i]:
            j += 1
            
    if j == n:
        print("Yes")
    else:
        print("No")