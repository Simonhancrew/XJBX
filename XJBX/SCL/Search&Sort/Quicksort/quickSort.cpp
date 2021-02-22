/*
    快排是分治思想排序的一个代表，总共可以分为三步
    选基
    分割
    递归

    首先选择一个pivot，将大于这个数的元素放到该数的右边，小于该数的放到该数左边
    之后递归的执行前两步直到区间不可再分

    实际实现的时候需要优雅的实现O(n)的时间复杂度和O(1)的空间复杂度
    如果实际场合没有写出O(1)的空间复杂度的话，也可以考虑开额外的空间
    比如开left[]和right[]两个数组，放两个部分的数
*/
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    return 0;
}