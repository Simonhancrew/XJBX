from typing import List

def quickSort(q:List,l:int,r:int):
    if l >= r:
        return
    i,j,x = l - 1,r + 1,q[l]
    while i < j:
        i += 1
        while q[i] < x:
            i += 1
        j -= 1
        while q[j] > x:
            j -= 1
        if i < j:
            q[i],q[j] = q[j],q[i]
    quickSort(q,l,j)
    quickSort(q,j + 1,r)

if __name__ == "__main__":
    input = [2,1,2,4,5]
    quickSort(input,0,4)
    for i in input:
        print(i)