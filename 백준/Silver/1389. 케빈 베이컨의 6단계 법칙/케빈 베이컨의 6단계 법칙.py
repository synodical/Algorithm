from collections import deque
from copy import copy
import queue


n, m = map(int, input().split())
adj = [[0]*n for i in range(n)]
copy = [[0]*n for i in range(n)]
queue = deque()


def bfs(a):
    queue.append(a)
    visit = [0 for i in range(n)]
    while queue:
        x = queue.popleft()
        visit[x] = True
        for i in range(0, n):
            if copy[x][i] == 1 and not visit[i]:
                copy[a][i] = copy[i][a] = copy[x][a] + 1
                visit[i] = True
                queue.append(i)

    return sum(copy[a])


for _ in range(m):
    a, b = map(int, input().split())
    adj[a-1][b-1] = 1
    adj[b-1][a-1] = 1

copy = adj
ans = [[0]*n for i in range(n)]
for i in range(0, n):
    ans[i] = bfs(i)

print(ans.index(min(ans))+1)
