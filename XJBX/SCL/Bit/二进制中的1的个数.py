if __name__ == "__main__":
    n = int(input())
    a = list(map(int,input().split()))
    for i in range(n):
        res,x = 0,a[i]
        while x > 0:
            x -= (x & -x)
            res += 1
        print(res,end=' ')