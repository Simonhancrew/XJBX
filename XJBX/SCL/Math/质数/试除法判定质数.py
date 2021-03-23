def is_prime(x):
    if x < 2:
        return False
    end = int(x ** 0.5)
    for num in range(2,end+1):
        if x % num == 0:
            return False
    return True

if __name__=="__main__":
    n = int(input())

    for i in range(n):
        t = int(input())
        if is_prime(t):
            print("Yes")
        else:
            print("No")