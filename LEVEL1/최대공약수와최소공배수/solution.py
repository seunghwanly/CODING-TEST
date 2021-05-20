def gcd(a,b):
    res = 0
    for i in range(1, min(a, b) +1 ):
        if a % i == 0 and b % i == 0: res = i
    return res

def solution(n, m):
    return [ gcd(n,m), int((n * m / gcd(n,m))) ]

print(solution(2, 5))