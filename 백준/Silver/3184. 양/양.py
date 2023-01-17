from collections import deque
import queue
from re import T


def bfs(a, b):
    queue = deque([(a, b)])
    wolf = 0
    sheep = 0
    while queue:
        x, y = queue.popleft()
        if arr[x][y] == "v":
            wolf += 1
        elif arr[x][y] == "o":
            sheep += 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= r or ny < 0 or ny >= c:
                continue
            if visit[nx][ny] or arr[nx][ny] == "#":
                continue
            visit[nx][ny] = True
            queue.append((nx, ny))

    return wolf, sheep


dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

r, c = map(int, input().split())
arr = []
visit = [[0]*c for i in range(r)]

for _ in range(r):
    arr.append(list(input().rstrip()))


wolf = 0
sheep = 0
for i in range(r):
    for j in range(c):
        if not visit[i][j]:
            w, s = bfs(i, j)
            if w < s:
                sheep += s
            else:
                wolf += w

print(sheep, wolf)
