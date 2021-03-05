from    typing import List
class MyQueue:

    def __init__(self):
        self.stk1 = list()


    def push(self, x: int) -> None:
        self.stk1.append(x)

    def pop(self) -> int:
        x = self.stk1[0]
        self.stk1 = self.stk1[1:]
        return x

    def peek(self) -> int:
        return self.stk1[0]

    def empty(self) -> bool:
        if len(self.stk1) > 0:
            return False
        else:
            return True