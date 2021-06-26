import copy
from typing import List
from collections import defaultdict

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        target = [[1,2,3],[4,5,0]]
        if target == board:
            return 0
        que = []
        que.append(board)
        dist = defaultdict(int)
        dist[str(board)] = 0
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        while que:
            t = que.pop(0)
            x,y = 0,0
            for i in range(2):
                for j in range(3):
                    if t[i][j] == 0:
                        x,y = i,j
                        break
            for i in range(4):
                nx,ny = x + dx[i],y + dy[i]
                if 0<= nx < 2 and 0<= ny < 3 :
                    st = copy.deepcopy(t)
                    st[x][y],st[nx][ny] = st[nx][ny],st[x][y]
                    if str(st) not in dist:
                        dist[str(st)] = dist[str(t)] + 1
                        if st == target:
                            return dist[str(st)]
                        que.append(st)
        return -1