# 一般过不掉

def get(l,r):
    return (h[r] - h[l - 1] * p[r - l + 1]) % q

if __name__ == "__main__":
    n,m = map(int,input().split())
    s = " "
    s += input().strip()
    P = 131
    q = 2 ** 64
    h = [0] * (n + 10)
    p = [0] * (n + 10)
    p[0] = 1
    for i in range(1,n+1):
        p[i] = (p[i-1] * P) % q
        h[i] = (h[i-1] * P + ord(s[i])) % q

    for i in range(m):
        l1,r1,l2,r2 = map(int,input().split())
        if get(l1,r1) == get(l2,r2):
            print("Yes")
        else:
            print("No")