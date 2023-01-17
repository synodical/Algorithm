def Eratos(N):
    sieve = [True for i in range(N + 1)]
    sieve[1] = False
    for i in range(2, int(N ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * 2, N + 1, i):
                sieve[j] = False
    return sieve

M, N = map(int, input().split())
anslist = Eratos(N)
for i in range(1, len(anslist)):
    if M <= i and anslist[i]:
        print(i)