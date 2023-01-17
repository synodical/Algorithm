import sys
n,m = map(int, input().split())
set = set()
ans = []
cnt = 0
for i in range(n):
    str = sys.stdin.readline().rstrip()
    set.add(str)

for i in range(m):
    str = sys.stdin.readline().rstrip()
    if str in set:
        cnt += 1
        ans.append(str)

print(cnt)
ans.sort()
for a in ans:
    print(a)
