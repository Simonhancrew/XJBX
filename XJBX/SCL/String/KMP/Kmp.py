if __name__=="__main__":
    n = int(input())
    p = input()
    m = int(input())
    s = input()
    ne = [0] * n
    ne[0] = -1
    j = -1

    for i in range(1,n):
        while(j >= 0 and p[i] != p[j + 1]):
            j = ne[j]
        if (p[i] == p[j + 1]):
            j += 1
        ne[i] = j

    j = -1
    for i in range(m):
        while j != -1 and s[i] != p[j + 1]: 
            j = ne[j]
        if s[i] == p[j + 1]:
            j += 1
        if j == n - 1 :
            print(i - n + 1,end = ' ')
            #有必要加上，不然的话会越界，因为结尾好像不是\0
            j = ne[j]
