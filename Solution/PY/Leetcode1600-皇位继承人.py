from collections import defaultdict
from typing import List
class ThroneInheritance:

    def __init__(self, kingName: str):
        self.dead = set()
        self.relation = defaultdict(list)
        self.king = kingName

    def birth(self, parentName: str, childName: str) -> None:
        self.relation[parentName].append(childName)

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        ans = []
        def dfs(name):
            if name not in self.dead:
                ans.append(name)
            if name in self.relation:
                for v in self.relation[name]:
                    dfs(v)
        dfs(self.king)
        return ans