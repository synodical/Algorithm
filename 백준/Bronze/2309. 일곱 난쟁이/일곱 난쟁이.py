height = []
sum = 0
ans = []
findAns = False

for i in range(9):
    height.append(int(input()))
    sum += height[i]
    
for i in range(9):
    sum -= height[i]
    for j in range(9):
        if i == j:
            continue
        sum -= height[j]
        
        if sum == 100:
            for k in range(9):
                if k != i and k !=j:
                    ans.append(height[k])
            findAns = True
            break
            
        sum += height[j]
    if findAns:
        break
    sum += height[i]
    
ans.sort()
for i in range(7):
    print(ans[i])