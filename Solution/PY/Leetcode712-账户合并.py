from typing import List
import collections
class  UnionFind():
    #self相当于this吗
    def __init__(self,n):
        self.parent = list(range(n))

    def find(self,x:int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self,x:int,y:int):
        self.parent[self.find(y)] = self.find(x)

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        email2Index = dict()
        email2name = dict()
        for account in accounts:
            name = account[0]
            for email in account[1:]:
                if email not in email2Index:
                    email2Index[email] = len(email2Index)
                    email2name[email] = name

        uf = UnionFind(len(email2Index))
        for account in accounts:
            firstIndex = email2Index[account[1]]
            for email in account[2:]:
                uf.union(firstIndex,email2Index[email])
        #当value时一个list的时候选用defaultdict
        index2email = collections.defaultdict(list)
        for email,index in email2Index.items():
            index = uf.find(index)
            index2email[index].append(email)
        ans = list()
        for emails in index2email.values():
            #python的默认排序函数，列表时可以+的
            ans.append([email2name[emails[0]]]+sorted(emails))
        return ans