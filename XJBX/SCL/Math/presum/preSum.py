if __name__ == "__main__":
    m,n = map(int,input().split())
    a = list(map(int,input().split()))
    #不处理边界就多开
    prefix = [0] * (m + 10)
    for i in range(m):
        prefix[i + 1] = prefix[i] + a[i]
    for i in range(n):
        l,r = map(int,input().split())
        print(prefix[r] - prefix[l - 1])