import sys
import math


def isPrime(number):
    if number == 1: return False
    if number == 2 and number == 3: return True
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0: return False
    return True


N = int(sys.stdin.readline().rstrip())
data = list(map(int, sys.stdin.readline().split()))
count = 0
for item in data:
    if isPrime(item): count += 1
print(count)