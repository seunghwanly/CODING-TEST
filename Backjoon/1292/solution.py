import sys


def sum(number):
    res = 0
    cnt = 0
    limit = 1
    while True:
        for i in range(limit):
            if cnt == number: return res
            res += limit
            cnt += 1
        limit += 1


A, B = map(int, sys.stdin.readline().split())

print(sum(B) - sum(A - 1))
