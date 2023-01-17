sum = 0
b = input().split(",")
b = list(map(int,b))
for i in range(len(b)):
    sum += b[i]
print(sum)