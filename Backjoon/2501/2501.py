N, K = map(int, input().split())

def getK(N, K):
    cnt = 1
    for i in range(1, N + 1):
        if N % i == 0:
            if cnt == K:
                return i
            cnt += 1
    return 0

print(getK(N, K))
