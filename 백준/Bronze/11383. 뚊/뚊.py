n,m =list(map(int,input().split()))
word,word2=[],[]
eyfa=True
for i in range(n):
    word.append(list(input()))
for i in range(n):
    word2.append(list(input()))
for i in range(n):
    for j in range(m*2):
        if word2[i][j]!=word[i][j//2]:
            eyfa=False
if eyfa:
    print("Eyfa")
else:
    print("Not Eyfa")