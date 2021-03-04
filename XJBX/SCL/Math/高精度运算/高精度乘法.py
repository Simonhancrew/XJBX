a = list(map(int,input()))

b = int(input())

A = a[::-1]


def mul(A,b):
    C  = list()
    t = 0
    for i in range(len(A)):
        t += A[i] * b
        C.append(t % 10)
        t = t // 10
    while t > 0:
        C.append(t % 10)
        t = t // 10
    while len(C) > 1 and C[-1] == 0:
        C.pop()

    return C    


if __name__ == "__main__":
    res = mul(A,b)
    for i in range(len(res) - 1,-1,-1):
        print(res[i],end = '')