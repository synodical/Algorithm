n = int(input())
for i in range(1, n + 1):
    a, b = input().split(' ')
    print('Case #%d: %d + %d = %d' %(i, int(a), int(b), int(a)+int(b)))