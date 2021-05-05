import sys
import math


def isPrime(num):
    if num == 1: return False
    if num <= 3: return True
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0: return False
    return True


M = int(sys.stdin.readline().rstrip())
N = int(sys.stdin.readline().rstrip())

min = 100001
sum = 0

for number in range(M, N + 1):
    if isPrime(number):
        if min > number:
            min = number
        sum += number

print(sum == 0 and -1 or sum)
if sum != 0: print(min)
