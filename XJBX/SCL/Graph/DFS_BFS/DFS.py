if __name__=="__main__":
    n = int(input())
    use = [0] * (n + 1)
    res = []
    def dfs(idx,end,res,use):
        if idx == end:
            for i in res:
                print(i,end = ' ')
            print("")
            return
        for i in range(1,end + 1):
            if use[i] == 0:
                use[i] = 1
                res.append(i)
                dfs(idx + 1,end,res,use)
                use[i] = 0
                res.pop()
    dfs(0,n,res,use)