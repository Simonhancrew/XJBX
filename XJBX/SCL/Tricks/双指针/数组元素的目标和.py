if __name__ == "__main__":
    n,m,x = map(int,input().split())

    a = list(map(int,input().split()))

    b = list(map(int,input().split()))

    j = m - 1

    for i in range(n):
        while j >= 0 and a[i] + b[j] > x:
            j -= 1
        if a[i] + b[j] == x:
            print(i,j)
            break