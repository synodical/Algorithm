n = str(input())
for i in range(len(n)):
    if len(n)>10:
        print(n[0:10])
        n = n[10:]
    else:
        print(n)
        break