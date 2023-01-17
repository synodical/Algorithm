a = list(input())
numi, numj = 0, 0
for i in range(len(a)-2):
    if a[i] == 'J' and  a[i+1] == 'O' and a[i+2] == 'I':
        numj += 1
    if a[i] == 'I' and a[i+1] == 'O' and a[i+2] == 'I':
        numi += 1
print(numj)
print(numi)