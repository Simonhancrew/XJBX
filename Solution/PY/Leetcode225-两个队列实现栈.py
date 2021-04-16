class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.que = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        tmp = [x]
        while len(self.que) > 0:
            tmp.append(self.que[0])
            self.que = self.que[1:]
        while len(tmp) > 0:
            self.que.append(tmp[0])
            tmp = tmp[1:]

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        first = self.que[0]
        self.que.pop(0)
        return first

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.que[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.que) == 0

