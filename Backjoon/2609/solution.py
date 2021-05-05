def min(x, y):
    return x > y and x or y

def gcd(x, y):
    res = -1
    for i in range(1, min(x, y) + 1):
        if x % i == 0 and y % i == 0:
            if res < i: res = i
    return res


N, M = map(int, input().split())

print(gcd(N, M))
print(gcd(N, M) * (N // gcd(N, M)) * (M // gcd(N, M)))
