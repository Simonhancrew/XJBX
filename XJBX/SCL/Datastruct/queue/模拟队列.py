if __name__ == "__main__":
    q = []
    n = int(input())
    for i in range(n):
        op = input().split()
        if op[0] == "push":
            q.append(op[1])
        elif op[0] == "pop":
                q = q[1:]
        elif op[0] == "empty":
            if q:
                print("NO")
            else:
                print("YES")
        else:
            print(q[0])