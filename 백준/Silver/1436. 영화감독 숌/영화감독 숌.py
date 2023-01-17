n = int(input())
cnt = 0
for i in range(10000000):
    j = str(i)
    if ("666" in j):
        cnt += 1
        if cnt == n:
            break
        i +=1   

print(i)