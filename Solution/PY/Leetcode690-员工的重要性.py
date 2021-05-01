class Solution:
    def __init__(self):
        self.res = 0
        self.employees = None
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        self.employees = employees
        self.res = 0
        def dfs(epl):
            self.res += epl.importance
            if not epl.subordinates:
                return 
            for ep in epl.subordinates:
                for worker in self.employees:
                    if worker.id == ep:
                        dfs(worker)
        for epl in employees:
            if epl.id == id:
                dfs(epl)
                break
        return self.res