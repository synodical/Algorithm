N = int(input())
sum = 0
i = 0
grade = []
grade = list(map(int, input().split()))
M = max(grade)
for i in range(N):
    grade[i] = grade[i]/M*100
    sum += grade[i]
print('%.2f' % (sum/N))