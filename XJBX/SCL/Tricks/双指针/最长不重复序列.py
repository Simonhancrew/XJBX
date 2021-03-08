if __name__ == "__main__":
    n = int(input())
    a = list(map(int,input().split()))
    b = [0] * int((1e5+10))
    res = 1
    j = 0
    for i in range(n):
        b[a[i]] += 1
        while b[a[i]] > 1:
            b[a[j]] -= 1
            j += 1
        res = max(res,i - j + 1)
        
    print(res)