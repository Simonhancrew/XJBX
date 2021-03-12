if __name__=="__main__":
    m = int(input())
    stk = []

    for i in range(m):
        op = input().split()
        if op[0] == "push":
            x = int(op[1])
            stk.append(x)
        elif op[0] == "pop":
            stk.pop()
        elif op[0] == "empty":
            if stk:
                print("NO")
            else:
                print("YES")
        elif op[0] == "query":
            if stk:
                print(stk[-1])