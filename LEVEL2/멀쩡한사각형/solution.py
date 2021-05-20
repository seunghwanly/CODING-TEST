def gcd(a,b):
    res = 1
    for i in range(1, min(a,b)+1):
        if a % i == 0 and b % i == 0: res = i
    return res

def solution(w,h):
    return w * h - (w + h - gcd(w,h))