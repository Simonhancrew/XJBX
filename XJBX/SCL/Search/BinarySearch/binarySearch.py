#二分查找的模板，注意循环中的if后接的check是要找的数的性质
#比如q[mid] <= x就是找的数都不大于x，最后l返回的就是上边界
'''
while l < r:
    mid = l + (r - l >> 1)
    if check(x):
        r = mid
    else:
        l = mid +1
'''
def upside(q,x):
    l,r = 0,len(q) - 1
    while l < r:
        mid = l + r + 1 >> 1
        if q[mid] <= x:
            l = mid
        else:
            r = mid - 1
    return l 


def downside(q,x):
    l,r = 0,len(q) - 1
    while l < r:
        mid = l + r >> 1
        if q[mid] >= x:
            r = mid 
        else:
            l = mid + 1
    return l

if __name__ == "__main__":
    input = [1,2,3,3,4,5,5,5,5,5,7,7,7,8,9,11,11,11,11,11,23]
    l = downside(input,5)
    r = upside(input,5)
    if l == 5 and r == 9:
        print("yes")
    else:
        print("wrong")

