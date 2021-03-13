if __name__=="__main__":
    stk = []
    n = int(input())
    data_in = map(int,input().split())
    for i in data_in:
        while stk and stk[-1] >= i:
            stk.pop()
        if stk:
            print(stk[-1],end = ' ')
        else:
            print(-1,end = ' ')
        stk.append(i)
