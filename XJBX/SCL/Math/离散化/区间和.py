if __name__=="__main__":
    n,m = map(int,input().split())
    add = list()
    all = list()
    for i in range(n):
        x,c = map(int,input().split())
        add.append([x,c])
        all.append(x)
    
    query = list()
    for i in range(m):
        l,r = map(int,input().split())
        query.append([l,r])
        all.append(l)
        all.append(r)
    
    def unique(all):
        j = 0
        n = len(all)
        for i in range(n):
            if i == 0 or all[i] != all[i - 1]:
                all[j] = all[i]
                j += 1
        return j
    
    
    def find(x):
        l ,r = 0,len(all) - 1
        while l < r:
            mid = l + r >> 1
            if all[mid] >= x:
                r = mid
            else:
                l = mid + 1
        return l + 1
        
    
    all.sort()
    all = all[:unique(all)]
    #或者是 all = list(set(all))
    
    a = [0] * 300010
    
    for item in add:
        index = find(item[0])
        a[index] += item[1]
    
    s = [0] * 300010
    
    for i in range(1,len(all) + 1):
        s[i] = s[i - 1] + a[i]
        
    
    for l,r in query:
        l1,r1 = find(l),find(r)
        print(s[r1] - s[l1 - 1])