import collections
from typing import List
class Solution(object):
    def removeStones(self, stones: List[List[int]]) -> int:
        """
        :type stones: List[List[int]]
        :rtype: int
        """
        n = len(stones)
        #python中哈希一般用collection
        #value是一个list
        edges = collections.defaultdict(list)
        rec = collections.defaultdict(list)
        #记录该行/列中有石头i
        #enumerate同时列出数据和下标
        #rec中的key是所有的行列
        for i,(x,y) in enumerate(stones):
            rec[x].append(i)
            rec[y+10001].append(i)
        #构建图
        #依照vec中所有的行列
        #不用rec的key时使用values（）
        for vec in rec.values():
            k = len(vec)
            for i in range(1,k):
                edges[vec[i-1]].append(vec[i])
                edges[vec[i]].append(vec[i-1])
        #不重复集合
        #set的添加add
        vis = set()
        def DFS(x):
            vis.add(x)
            for y in edges[x]:
                if y not in vis:
                    DFS(y)

        num = 0
        for i in range(n):
            if i not in vis:
                num += 1
                DFS(i)

        return n - num