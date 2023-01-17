import sys
input = sys.stdin.readline

t = int(input())
switch = list(map(int, input().split()))
student = int(input())

for _ in range(student):
    gender, n = map(int, input().split())
    if gender == 1: # 남자인 경우
        i = n
        while n-1 < t:
            switch[n-1] ^= 1
            n += i
    else:
        switch[n-1] ^= 1
        length = min(t-n, n) - 1 # t=8, n=3이면 length는 2
        # 즉 n 기준 좌측과 우측 각각의 최대길이
        # i = n-length-1; j =n+length-1
        i = n-2; j=n
        while i >= 0 and j < t:
            if switch[i] == switch[j]:
                switch[i] ^= 1
                switch[j] ^= 1
            else:
                break
            i -= 1; j += 1

for i in range(0, t, 20):
    print(*switch[i:i+20])