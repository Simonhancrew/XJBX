if __name__=="__main__":
    n,m = map(int,input().split())
    p = [i for i in range(n + 1)]
    
    #list就直接是全局了，不需要再声明
    #但是普通变量会有歧义，需要在函数内部global
    def find(x):
        if x != p[x]:
            p[x] = find(p[x])
        return p[x]
    
    for i in range(m):
        op,a,b = input().split()
        a,b = int(a),int(b)
        if op == 'M':
            p[find(a)] = find(b)
        else:
            if find(a) == find(b):
                print("Yes")
            else:
                print("No")